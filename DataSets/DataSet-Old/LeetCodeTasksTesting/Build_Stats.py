import os
import json
import pandas as pd
import plotly.graph_objs as go
from sklearn.metrics import confusion_matrix, precision_score, recall_score, f1_score
from plotly.subplots import make_subplots
# Function to parse task_info.json and result_{Good,Bad}.json files
def parse_folder(folder_path):
    with open(os.path.join(folder_path, 'task_info.json'), 'r') as f:
        task_info = json.load(f)
    with open(os.path.join(folder_path, 'results_Good.json'), 'r') as f:
        result_good = json.load(f)
    with open(os.path.join(folder_path, 'results_Bad.json'), 'r') as f:
        result_bad = json.load(f)
    return {
        'name': task_info['name'],
        'id': task_info['id'],
        'difficulty': task_info['difficulty'],
        'tags': task_info['tags'],
        'output_good': result_good['errors'],
        'output_bad': result_bad['errors'],
        'returncode_good': result_good['returncode'],
        'returncode_bad': result_bad['returncode']
    }

# Function to collect data from folders inside Tests directory
def collect_data():
    data = []
    for task_name in os.listdir('Tests'):
        folder_path = os.path.join('Tests', task_name)
        data.append(parse_folder(folder_path))
    return data

# Function to build confusion matrix
def build_confusion_matrix(y_true, y_pred):
    tn, fp, fn, tp = confusion_matrix(y_true, y_pred).ravel()
    return tn, fp, fn, tp

# Collect data
data = collect_data()
df = pd.DataFrame(data)

# Calculate TP, TN, FP, FN
df['TP'] = (df['returncode_good'] == 0).astype(int)
df['TN'] = (df['returncode_bad'] != 0).astype(int)
df['FP'] = (df['returncode_bad'] == 0).astype(int)
df['FN'] = (df['returncode_good'] != 0).astype(int)

# Define TP, TN, FP, FN
TP = df['TP'].sum()
TN = df['TN'].sum()
FP = df['FP'].sum()
FN = df['FN'].sum()

# Calculate recall and precision
recall = TP / (TP + FN) 
precision = TP / (TP + FP)

# Calculate F1 score
f1 = 2 * precision * recall / (precision + recall)

# Build confusion matrix
conf_matrix = build_confusion_matrix(df['returncode_good'], df['returncode_bad'])

# Plot graphs
fig = go.Figure(data=[
    go.Bar(name='True Positive', x=['TP'], y=[df['TP'].sum()]),
    go.Bar(name='True Negative', x=['TN'], y=[df['TN'].sum()]),
    go.Bar(name='False Positive', x=['FP'], y=[df['FP'].sum()]),
    go.Bar(name='False Negative', x=['FN'], y=[df['FN'].sum()])
])
fig.update_layout(barmode='group')

fig2 = go.Figure()

fig2.add_trace(go.Bar(x=['Precision'], y=[precision], name='Precision'))
fig2.add_trace(go.Bar(x=['Recall'], y=[recall], name='Recall'))
fig2.add_trace(go.Bar(x=['F1 Score'], y=[f1], name='F1 Score'))

fig2.update_layout(
                  xaxis_title='Метрика',
                  yaxis_title='Значение')

# Plot confusion matrix


# Create a custom confusion matrix
conf_matrix_data = [
    [TP, FP],
    [FN, TN]
]

# Plot confusion matrix
fig_custom_conf_matrix = go.Figure(data=go.Heatmap(
    z=conf_matrix_data,
    x=['Положительный', 'Отрицательный'],
    y=['Положительный', 'Отрицательный'],
    colorscale='Viridis',
    reversescale=True  # Reverse color scale for better visualization
))

# Customize layout
fig_custom_conf_matrix.update_layout(
    xaxis_title='Предсказание',
    yaxis_title='Фактический'
)

# Calculate successful and failed tests
successful_tests = df[(df['returncode_good'] == 0) & (df['returncode_bad'] != 0)].shape[0]
failed_tests = df[(df['returncode_good'] != 0) | (df['returncode_bad'] == 0)].shape[0]

# Create pie chart data

labels = ['Успешные тесты', 'Неудачные тесты']
values = [successful_tests, failed_tests]

# Plot pie chart
fig_pie_chart = go.Figure(data=[go.Pie(labels=labels, values=values)])

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


# Create subplots for each difficulty level
multi_pie = make_subplots(rows=1, cols=3, subplot_titles=("Easy", "Medium", "Hard"),  specs=[[{"type": "pie"}, {"type": "pie"}, {"type": "pie"}]])

for i, difficulty_level in enumerate(['Easy', 'Medium', 'Hard']):
    # Filter data for the current difficulty level
    filtered_df = df[df['difficulty'] == difficulty_level]
    
    # Count successful and failed tests
    successful_tests = filtered_df[(filtered_df['returncode_good'] == 0) & (filtered_df['returncode_bad'] != 0)].shape[0]
    failed_tests = filtered_df[(filtered_df['returncode_good'] != 0) | (filtered_df['returncode_bad'] == 0)].shape[0]
    
    # Create pie chart data
    labels = ['Успешные тесты', 'Неудачные тесты']
    values = [successful_tests, failed_tests]

    # Add pie chart subplot
    multi_pie.add_trace(go.Pie(labels=labels, values=values), row=1, col=i+1)

# Save figure
save_fig(multi_pie, 'Successful_vs_Failed_Difficulty_Levels')
save_fig(fig_pie_chart, 'Successful_vs_Failed_Tests')
save_fig(fig_custom_conf_matrix, 'Confusion_Matrix')
save_fig(fig, 'TP_TN_FP_FN')
save_fig(fig2, 'Precision_Recall_F1')
