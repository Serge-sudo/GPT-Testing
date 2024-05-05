import os
import shutil
import subprocess
import json
import sys
import threading
import signal

# Base directory paths
BASE_DIR = os.getcwd()
GOOD_DIR = os.path.join(BASE_DIR, 'Good')
BAD_DIR = os.path.join(BASE_DIR, 'Bad')
TESTS_DIR = os.path.join(BASE_DIR, 'Tests')

# Timeout for each test in seconds (adjust as needed)
TEST_TIMEOUT = 10


def run_with_timeout(cmd, cwd):
    """Run a command with a timeout."""
    proc = None
    def target():
        nonlocal proc
        proc = subprocess.Popen(cmd, cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        out, err = proc.communicate()
        result['output'] = out
        result['errors'] = err
        result['returncode'] = proc.returncode

    result = {}
    thread = threading.Thread(target=target)
    thread.start()
    thread.join(TEST_TIMEOUT)
    if thread.is_alive():
        proc.kill()
        result['output'] = ''
        result['errors'] = 'Test timed out'
        result['returncode'] = 1

    return result


def copy_and_test_solution(src_folder_name, src_folder_path):
    print(f"Starting to process solutions from: {src_folder_path}")
    for task_name in os.listdir(src_folder_path):
        task_path = os.path.join(src_folder_path, task_name)
        solution_path = os.path.join(task_path, 'solution.py')
        info_path = os.path.join(task_path, 'task_info.json')
        test_dir = os.path.join(TESTS_DIR, task_name)

        if not os.path.exists(test_dir):
            print(f"Test directory {test_dir} doesn't exist. Skipping task: {task_name}.")
            continue

        # Copy the solution.py file into the test directory
        target_solution_path = os.path.join(test_dir, 'solution.py')
        target_info_path = os.path.join(test_dir, 'task_info.json')
        shutil.copy(solution_path, target_solution_path)
        print(f"Copied solution.py from {task_path} to {test_dir}")
        shutil.copy(info_path, target_info_path)
        print(f"Copied task_info.json from {task_path} to {test_dir}")

        # Run the test.py file in a separate thread with timeout
        test_script = os.path.join(test_dir, 'test.py')
        test_results = run_with_timeout([sys.executable, test_script], cwd=test_dir)

        # Write results to a unique JSON file in the test directory
        results_file = os.path.join(test_dir, f'results_{src_folder_name}.json')
        with open(results_file, 'w') as json_file:
            json.dump(test_results, json_file, indent=4)
        print(f"Test results for {task_name} ({src_folder_name}) written to {results_file}")

        # Remove the copied solution.py
        if os.path.exists(target_solution_path):
            os.remove(target_solution_path)
            print(f"Removed copied solution.py from {test_dir}")

    print(f"Finished processing solutions from: {src_folder_path}")


# Execute the testing process for both Good and Bad folders
copy_and_test_solution('Good', GOOD_DIR)
copy_and_test_solution('Bad', BAD_DIR)

print("Testing completed.")
