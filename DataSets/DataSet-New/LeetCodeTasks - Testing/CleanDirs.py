import os
import shutil

def clean_bad_directory(bad_folder_path):
    # Iterate through directories inside the "Bad" folder
    for task_name_dir in os.listdir(bad_folder_path):
        task_path = os.path.join(bad_folder_path, task_name_dir)
        
        # Ensure it's a directory
        if os.path.isdir(task_path):
            python3_solution_path = os.path.join(task_path, 'solutions', 'python3', 'solution.py')
            destination_path = os.path.join(task_path, 'solution.py')
            
            # Check if the solution file exists in the "python3" subfolder
            if os.path.isfile(python3_solution_path):
                # Move the solution.py file to the parent task_name directory
                shutil.move(python3_solution_path, destination_path)
                
                # Remove the "solutions" folder entirely
                solutions_path = os.path.join(task_path, 'solutions')
                shutil.rmtree(solutions_path)

# Update 'path_to_bad_folder' with the actual path to your "Bad" folder
path_to_bad_folder = 'Bad'
clean_bad_directory(path_to_bad_folder)
path_to_bad_folder = 'Good'
clean_bad_directory(path_to_bad_folder)
