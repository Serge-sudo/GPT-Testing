import os
import json
import pandas as pd
import plotly.express as px
from plotly.subplots import make_subplots
import plotly.graph_objects as go

# Function to parse task_info.json and results.json files
def parse_task(folder):
    task_info_path = os.path.join(folder, 'task_info.json')
    results_path = os.path.join(folder, 'result.json')
    with open(task_info_path, 'r') as f:
        task_info = json.load(f)
    with open(results_path, 'r') as f:
        results = json.load(f)
    return task_info, results

# Function to iterate over all folders inside Fixed and collect statistics
def collect_statistics(root_folder):
    data = []
    for taskName in os.listdir(root_folder):
        dirpath = os.path.join(root_folder, taskName)
        task_info, results = parse_task(dirpath)
        for lang, result in results.items():
            task_stats = {
            'Name': task_info['name'],
            'Difficulty': task_info['difficulty']
            }
            task_stats[f'lang'] = lang
            task_stats[f'pass_Count'] = result['pass_cnt']
            task_stats[f'result'] = result['result']
            if result['result'] == 'Accepted':
                task_stats[f'Fixed'] = 1
            else:
                task_stats[f'Fixed'] = 0
            data.append(task_stats)
    return data


root_folder = 'Fixed'
data = collect_statistics(root_folder)

# Create a pandas DataFrame
df = pd.DataFrame(data)

# Pie chart of fixed tasks vs all tasks
fixed_tasks_count = df[df['Fixed'] == 1]['Fixed'].count()
total_tasks_count = len(os.listdir(root_folder)) * 4 # lang count 
fixed_percentage = fixed_tasks_count / total_tasks_count * 100
not_fixed_percentage = 100 - fixed_percentage

fig1 = px.pie(names=['Исправлена', 'Не исправлена'], values=[fixed_percentage, not_fixed_percentage])

unique_languages = df['lang'].unique()
fig2 = make_subplots(rows=2, cols=2,specs=[[{"type": "pie"}, {"type": "pie"}], [{"type": "pie"},{"type": "pie"}]],)

# Iterate through languages and create pie charts on subplots
for i, lang in enumerate(unique_languages):
    lang_data = df[df['lang'] == lang]
    fixed_count = lang_data[lang_data['Fixed'] == 1]['Fixed'].count()
    total_count = len(lang_data)
    fixed_perc = fixed_count / total_count * 100
    not_fixed_perc = 100 - fixed_perc

    fig2.add_trace(go.Pie(labels=['Исправлена', 'Не исправлена'], values=[fixed_perc, not_fixed_perc], title=lang,titleposition='bottom center'), row=(i // 2) + 1, col=(i % 2) + 1)



unique_dif = df['Difficulty'].unique()
fig3 = make_subplots(rows=1, cols=3,specs=[[{"type": "pie"}, {"type": "pie"}, {"type": "pie"}]])

# Iterate through languages and create pie charts on subplots
for i, dif in enumerate(unique_dif):
    dif_data = df[df['Difficulty'] == dif]
    fixed_count = dif_data[dif_data['Fixed'] == 1]['Fixed'].count()
    total_count = len(dif_data)
    fixed_perc = fixed_count / total_count * 100
    not_fixed_perc = 100 - fixed_perc

    fig3.add_trace(go.Pie(labels=['Исправлена', 'Не исправлена'], values=[fixed_perc, not_fixed_perc], title=dif,titleposition='bottom center'), row=1, col=i + 1)

# Base directory for charts
charts_dir = 'plotly_charts'
os.makedirs(charts_dir, exist_ok=True)

# Subdirectories for HTML and PNG formats
html_dir = os.path.join(charts_dir, 'html')
png_dir = os.path.join(charts_dir, 'png')
os.makedirs(html_dir, exist_ok=True)
os.makedirs(png_dir, exist_ok=True)

# Define a function to save figures in both HTML and PNG formats
def save_fig(fig, filename):
    html_file = os.path.join(html_dir, f'{filename}.html')
    png_file = os.path.join(png_dir, f'{filename}.png')
    
    # Save as HTML
    fig.write_html(html_file)
    # Save as PNG
    fig.write_image(png_file)


save_fig(fig1, 'fixed_vs_all')
save_fig(fig2, 'fixed_vs_all_lang')
save_fig(fig3, 'fixed_vs_all_dif')
