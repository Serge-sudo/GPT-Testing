import os
import json
import pandas as pd
import plotly.express as px
import pandas as pd

# Path to the LeetCodeTasks directory
dir_path = 'LeetCodeTasks'

# Check if the final DataFrame file already exists
final_dataframe_path = 'final_dataframe.csv'

# Get all folders in the directory
folders = [f for f in os.listdir(dir_path) if os.path.isdir(os.path.join(dir_path, f))]
# Sort folders based on the numeric part of the folder name
folders.sort(key=lambda x: int(x.split('_')[0]))
print("Folders sorted.")
folders = folders[:]
# List to keep track of all task data
all_tasks = []

for folder in folders:
    folder_path = os.path.join(dir_path, folder)
    print(f"Processing folder: {folder}")

    # Paths to the JSON files
    task_info_path = os.path.join(folder_path, 'task_info.json')
    result_path = os.path.join(folder_path, 'result.json')

    # Read task_info.json
    with open(task_info_path, 'r') as file:
        task_info = json.load(file)

    # Read result.json
    with open(result_path, 'r') as file:
        results = json.load(file)

    # Extract results for different programming languages
    for lang, lang_data in results.items():
        task_dict = {
            'task_id': task_info['id'],
            'task_name': task_info['name'],
            'difficulty': task_info['difficulty'],
            'tags': ', '.join(task_info['tags']),
            'language': lang,
            'result': lang_data['result'],
            'pass_cnt': lang_data['pass_cnt'],
            'Memory': lang_data['Memory'],
            'Runtime': lang_data['Runtime']
        }
        all_tasks.append(task_dict)
# Create a DataFrame from all collected task data
if all_tasks:
    df = pd.DataFrame(all_tasks)
    df.to_csv(final_dataframe_path, index=False)
    print(f"Final DataFrame saved to {final_dataframe_path}")
else:
    print("No task data collected.")


# Base directory for charts
charts_dir = 'plotly_charts'
os.makedirs(charts_dir, exist_ok=True)

# Subdirectories for HTML and PNG formats
html_dir = os.path.join(charts_dir, 'html')
png_dir = os.path.join(charts_dir, 'png')
os.makedirs(html_dir, exist_ok=True)
os.makedirs(png_dir, exist_ok=True)
# Assuming df is your DataFrame
df = pd.read_csv(final_dataframe_path)

# Define a function to save figures in both HTML and PNG formats
def save_fig(fig, filename):
    html_file = os.path.join(html_dir, f'{filename}.html')
    png_file = os.path.join(png_dir, f'{filename}.png')
    
    # Save as HTML
    fig.write_html(html_file)
    # Save as PNG
    fig.write_image(png_file)


# Расчет средней производительности по языкам программирования
avg_performance_by_lang = df.groupby('language')[['Runtime', 'Memory']].mean().reset_index()

fig_lang = px.bar(avg_performance_by_lang, x='language', y=['Runtime', 'Memory'],
                  labels={'value':'Эффективность (%)', 'variable':'Метрика', 'language' : 'Язык'},
                  barmode='group')
save_fig(fig_lang, 'average_runtime_memory_efficiency_by_language')

fig_difficulty = px.box(df, x='difficulty', y=['Runtime', 'Memory'],
                        labels={'value':'Эффективность (%)', 'variable':'Метрика', 'difficulty':'Сложность'},
                        color='variable')  # Разные цвета для времени выполнения и использования памяти
save_fig(fig_difficulty, 'efficiency_by_difficulty')

# Сначала разделяем теги и расширяем DataFrame, так чтобы каждый тег был в отдельной строке
df_exploded = df.assign(tags=df['tags'].str.split(', ')).explode('tags')

# Расчет средней производительности и количества задач по тегам
performance_count_by_tag = df_exploded.groupby('tags').agg({
    'Runtime': 'mean',
    'Memory': 'mean',
    'task_id': 'count'  # Предполагая, что 'task_id' можно использовать для подсчета задач
}).reset_index()

# Создание диаграммы рассеивания
fig_tags = px.scatter(performance_count_by_tag, x='Runtime', y='Memory', 
                      color='tags', size='task_id',
                      labels={'Runtime': 'Средняя эффективность времени выполнения (%)', 
                              'Memory': 'Средняя эффективность использования памяти (%)',
                              'task_id': 'Количество задач'})

save_fig(fig_tags, 'scatter_plot_efficiency_by_tags')

# Pie Chart of Task Results
fig = px.pie(df, names='result')
save_fig(fig, 'task_results_distribution')

# other graphs
# Convert tags into a list
# Tags vs. Acceptance Ratio
tags_expanded = df.drop('tags', axis=1).join(
    df['tags'].str.split(', ', expand=True).stack().reset_index(level=1, drop=True).rename('tag')
)
tag_acceptance = tags_expanded.pivot_table(index='tag', columns='result', aggfunc='size', fill_value=0)
tag_acceptance['acceptance_ratio'] = tag_acceptance.get('Accepted', 0) / tag_acceptance.sum(axis=1)
fig1 = px.bar(tag_acceptance, y='acceptance_ratio', labels={'tag':'Маркировка',"acceptance_ratio":'Пропорция принятия'}, color='acceptance_ratio',)
save_fig(fig1, 'acceptance_ratio_by_tag')

# Language vs. Acceptance Ratio
lang_acceptance = df.pivot_table(index='language', columns='result', aggfunc='size', fill_value=0)
lang_acceptance['acceptance_ratio'] = lang_acceptance.get('Accepted', 0) / lang_acceptance.sum(axis=1)
fig2 = px.bar(lang_acceptance, y='acceptance_ratio',labels={'language': 'Язык', 'acceptance_ratio':'Пропорция принятия'},color='acceptance_ratio')
save_fig(fig2, 'acceptance_ratio_by_language')

# Difficulty vs. Acceptance Ratio
difficulty_acceptance = df.pivot_table(index='difficulty', columns='result', aggfunc='size', fill_value=0)
difficulty_acceptance['acceptance_ratio'] = difficulty_acceptance.get('Accepted', 0) / difficulty_acceptance.sum(axis=1)
fig3 = px.bar(difficulty_acceptance, y='acceptance_ratio',labels={'difficulty': 'Сложность', 'acceptance_ratio':'Пропорция принятия'},color='acceptance_ratio')
save_fig(fig3, 'acceptance_ratio_by_difficulty')

# Count the number of languages each task was accepted in
# Generate a DataFrame indicating if a task was accepted in a language
df['accepted'] = (df['result'] == 'Accepted')

# Group by task and language, and determine if any were accepted in each language
task_language_accepted = df.groupby(['task_id', 'language'])['accepted'].any().unstack(fill_value=False)

# Count how many languages each task was accepted in
task_language_count = task_language_accepted.sum(axis=1)

# Get the value counts for each number of languages (0 through the number of languages considered)
distribution_across_languages = task_language_count.value_counts().reindex(range(task_language_accepted.shape[1] + 1), fill_value=0)
custom_names = [f"На {i} языках" for i in distribution_across_languages.index]
# Generate the pie chart
fig4 = px.pie(distribution_across_languages, values=distribution_across_languages, names=custom_names)

save_fig(fig4, 'task_distribution_by_language_acceptance')


# Filter out 'Accepted' and count errors by language
errors = df[df['result'] != 'Accepted']
error_types = errors.groupby(['language', 'result']).size().unstack().fillna(0)
fig5 = px.bar(error_types, labels={'language': 'Язык', 'value':'Кольчество', 'result':'Результат'})
save_fig(fig5, 'error_types_by_language')


# Define error types
error_types = ['Wrong Answer', 'Runtime Error', 'Time Limit Exceeded', 'Memory Limit']

# Calculate pass rate for error types
error_pass_rate = df[df['result'].isin(error_types)]
error_pass_rate['Прошла 75% тестов'] = error_pass_rate['pass_cnt'].map(lambda x : int(x.split("/")[0].strip())) >= error_pass_rate['pass_cnt'].map(lambda x : int(x.split("/")[1].strip())) * 0.75 
pass_rate = error_pass_rate.groupby('result')['Прошла 75% тестов'].mean()
fig6 = px.bar(pass_rate, labels={'value': 'Пропорция пройденных тестов', 'variable':'Переменная', 'result':'Результат'})
save_fig(fig6, 'test_pass_rate_for_errors')


