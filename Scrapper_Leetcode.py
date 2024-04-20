import requests
import os
import json
import pandas as pd
import time
from leetscrape import GetQuestionsList, GetQuestion


def create_task_folders(data):
    base_dir = "LeetCodeTasks"
    os.makedirs(base_dir, exist_ok=True)
    num = 0
    for item in data.values():
        print(f'fetching {num}-{item["titleSlug"]}')
        num+=1
        while True:
            try:
            # Attempt to scrape the question data
                task = GetQuestion(titleSlug=item["titleSlug"]).scrape()
                break  # If scrape is successful, break out of the loop
            except Exception as e:
            # Handle the exception (e.g., print error message, wait before retrying)
                print(f"An error occurred: {e}. Retrying...")
                time.sleep(1)  # Wait for 1 second before retrying to avoid hammering the server too quickly
            # Assuming GetQuestion().scrape() returns a task object with necessary attributes
        if task.isPaidOnly:
            print("Skiping paid task")
            continue
        task_id = task.QID
        task_title_slug = task.titleSlug 
        task_dir = os.path.join(base_dir, f"{task_id}_{task_title_slug}")
        os.makedirs(task_dir, exist_ok=True)
        
        # Create a JSON file for task info
        task_info = {
            "name": task.title,
            "id": task_id,
            # Assuming tags/topics are correctly handled if needed
            "difficulty": task.difficulty,
            "tags": task.topics
        }
        with open(os.path.join(task_dir, 'task_info.json'), 'w', encoding="utf-8") as f:
            json.dump(task_info, f, indent=4)

        with open(os.path.join(task_dir, 'task.md'), 'w', encoding="utf-8") as f:
             f.write(str(task))

        solutions_dir = os.path.join(task_dir, 'solutions')
        os.makedirs(solutions_dir, exist_ok=True)
        
        # Define correct extensions for each language
        languages = {
            "cpp": "cpp",
            "c": "c",
            "python3": "py",
            "java": "java"
        }
        
        # Create language-specific folders and template files
        for lang, ext in languages.items():
            lang_dir = os.path.join(solutions_dir, lang)
            os.makedirs(lang_dir, exist_ok=True)

            # Adjust to use a specific template or generic code, if available
            template_code = task.Code

            # Write the template code into a file with the appropriate extension
            template_file_path = os.path.join(lang_dir, f'template.{ext}')
            with open(template_file_path, 'w', encoding="utf-8") as f:
                f.write(template_code[lang])

            task_info = {
                "CE": "",
                "RE": "",
                "TL": "",
                "WA": "",
                "OK": ""
            }
            results = os.path.join(lang_dir, 'results.json')
            with open(results, 'w', encoding="utf-8") as f:
                json.dump(task_info,  f, indent=4)

            # Create an empty solution file
            solution_file_path = os.path.join(lang_dir, f'solution.{ext}')
            with open(solution_file_path, 'w', encoding="utf-8") as f:
                pass
        

    print(f"done fetching")


N = 150

res = pd.DataFrame()
for i in range(N // 5):
    print(f"GETING QUESTION FROM {i * 5} TO {(i+1) * 5}")
    ls = GetQuestionsList(limit=5,skip=i*5)
    ls.scrape()
    # print(ls.questions.head())
    res = pd.concat([res,ls.questions.head()], ignore_index=True)

print(res)
res = res.to_dict('index')
create_task_folders(res)