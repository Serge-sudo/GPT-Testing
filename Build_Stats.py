import os
import json
import pandas as pd

# Path to the LeetCodeTasks directory
dir_path = 'LeetCodeTasks'

# Check if the final DataFrame file already exists
final_dataframe_path = 'final_dataframe.csv'
if os.path.exists(final_dataframe_path):
    print("Final DataFrame already exists.")
else:
    # Get all folders in the directory
    folders = [f for f in os.listdir(dir_path) if os.path.isdir(os.path.join(dir_path, f))]
    # Sort folders based on the numeric part of the folder name
    folders.sort(key=lambda x: int(x.split('_')[0]))
    print("Folders sorted.")

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
                'pass_cnt': lang_data['pass_cnt']
            }
            all_tasks.append(task_dict)
        break    
    # Create a DataFrame from all collected task data
    if all_tasks:
        df = pd.DataFrame(all_tasks)
        df.to_csv(final_dataframe_path, index=False)
        print(f"Final DataFrame saved to {final_dataframe_path}")
    else:
        print("No task data collected.")


import os

# Base directory for charts
charts_dir = 'plotly_charts'
os.makedirs(charts_dir, exist_ok=True)

# Subdirectories for HTML and PNG formats
html_dir = os.path.join(charts_dir, 'html')
png_dir = os.path.join(charts_dir, 'png')
os.makedirs(html_dir, exist_ok=True)
os.makedirs(png_dir, exist_ok=True)
import plotly.express as px
import pandas as pd
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

# Pie Chart of Task Results
fig = px.pie(df, names='result', title='Overall Distribution of Task Results')
save_fig(fig, 'task_results_distribution')

# Bar Chart of Pass Count by Programming Language
df['passed_tests'] = df['pass_cnt'].apply(lambda x: int(x.split('/')[0].strip()))
df['total_tests'] = df['pass_cnt'].apply(lambda x: int(x.split('/')[1].strip()))
fig = px.bar(df, x='language', y=['passed_tests', 'total_tests'], title='Passed Tests vs. Total Tests by Programming Language',
             labels={'value': 'Number of Test Cases', 'variable': 'Type of Test Cases'},
             barmode='group')
save_fig(fig, 'pass_count_by_language')

# Histogram of Pass Rates
df['pass_rate'] = (df['passed_tests'] / df['total_tests']) * 100
fig = px.histogram(df, x='pass_rate', nbins=30, title='Distribution of Pass Rates',
                   labels={'pass_rate': 'Pass Rate (%)'})
save_fig(fig, 'pass_rate_distribution')

# Box Plot of Pass Rates by Difficulty
fig = px.box(df, x='difficulty', y='pass_rate', title='Pass Rates by Difficulty',
             labels={'pass_rate': 'Pass Rate (%)'})
save_fig(fig, 'pass_rate_by_difficulty')

# Stacked Bar Chart of Results by Difficulty
result_counts = df.groupby(['difficulty', 'result']).size().reset_index(name='counts')
fig = px.bar(result_counts, x='difficulty', y='counts', color='result', title='Task Results by Difficulty',
             labels={'counts': 'Number of Tasks'})
save_fig(fig, 'results_by_difficulty')
print('Stats are ready.')
