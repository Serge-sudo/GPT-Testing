import os
from Libs.pychatgpt import ChatGPT
import time
# Set up your session token for ChatGPT API
session_token = 'eyJhbGciOiJkaXIiLCJlbmMiOiJBMjU2R0NNIn0..Am325wpjG2MzR46t.1CzjkLDF9LpkE18byMuanZuSS_GgQuFT5T2s3aPuL40k39N4UoGmu9hwWCt5qhRHKMbohFU-smAslMDmW4rkdbasjseM8JyfsmzFaWBulw99vHQzMXvBWk7BTmctnDYjPoytDvX35uQaCjaQW3q8nW5rH_YZSzmQm1eC9iSSPk2WIPkpH2lIbV2J6GTc6DUXME2AlcfJDol3nKy7yFXF68ARPCX0Oxrcvr_BpY5TMOYKmw3qb2hGVM5p4IA1DbLFogJ_bcpRiYUB-4dpAO4BWArmAW05RMDkUI-5lDzTMk8dBIq0KSz5PXTDlNN7I3Ti40qDWY_HB61I60nm3ZkTebmmbX5xuqcObU-qrskcjyxeM5mr9PDusjs68RbbNy_AGwHo8YSbFwCUpYvA3VRFCfm9yUDBImUJp80sUXaGSd-b-aINOFnyHpJG4Tkhmz0KItE4MR2qMTTMJbzNwZ6p9gfcwZI9wdJf-2emhnnHrNNSaTULVRTBRpbsdIueyMyGyjJDH7QZSR5nzOpRcpoj02eeAOL-_fCrJDC6rEIYtI_mtx8zuERz6ZtRdraTsPMxLodxncdhqz3YY09gVufBbkVRG7BcmbNWDTisOVkb-MVM9hwtHNCYWphTId_gOmgOCWv8CK8HMCgDZox8Ia1d3J0Eg4jpVKeUjzIbtbFTygzfFMwFliZS7h3CEOipWgbtmaDi3bTvJdSAyrbYqYimHTWLjG4MrKbhaQvnEN2K6aAhSxLyNqDHxeW9BU8Nu5xw1UFFFPIGCDOCB8ZmFqMiHY49721_kWnd6beWM-a4HUlCnIYiU9_NGBqvr_uGysq0p0YlVImJeyp_ed0VMnGsGs3cUxLiuwKIJjU1QVHwViR_QQZBRZO2ciFiTP5d7KxzRGEdevOgVthIo0QH26nC6CrPloPelqsBjRyT21KlmV4zxxp-oWgUNHn3V4_0TxxkELpBZIDJZ_vCAhXVE2Ks235u4yJER4fyTbuYmxOpvgV8lX9G2V3Q1Iy4tBKzPpk1zJae75kGP7Nf-RR8xOdShvfb5PSyxOYjLwtWDhIThQ6RosaOAZr4IrHqG-gSmKL_oXMXgxSaF8XHTQ3aVGssZe5KKG6eKlfbyqd2CBMpeIavNDSdyLZQShkmb7PKXgtKMw9tSKHIfTgJd8Idg3oa4fEfTQ3HXZcJrmNu74lC4AQmMzdzbM621IIZYHUSl_ZrVN0nsQyaG2i1JAWix6XZBGzSZO5AuC8-hn4oixC1nD_OkZtJk3M92pyNTNyzz02ZGOvaUm5BUEqjGzDi0WeeDu0jqWPJkIz9Pwn6BEBcuZlo7To8GRu-DUrWqqJwMzqB_UBAqaNx_IxPEuiVyRsWR1z4dV-2dnpYO8pGkKmx8JuDu3N0d2u0Af-C7SyaRLQNfMhMF5OL0unUGUQnMy7J6CuA0xSXxTajUWwu_MBycQ2HakgtlCfLRjdNzeCfaSe2nJKSskktJqFmeunE8fmywyHvDgNj688ZBtT8-XUZxPaH5DYQiNzyKGKHYQ2qwjhHYxdx8x-LqadERGKsujCNqrrj50hBQ7lWL2F1bvPhb7mEDDiy8NhvCrkNsZHvcmc9UMWAXHnwjQ-Vzf2R7LkEhwsQ7XiHO4P6gIezteP6oLLpzNFhPeTgcYLE13xei2rnlzLh9-5JIta9FvF25a65BXeEa3HeqctRsxJ1cza0dt1bgcsHnsxtSsGY2bGB3SqbNqe4QivIqhPmfGUv5hAtCuJPqadwNeyb9r-h_nV-ZoohpZQiIuHPmTQBLvMsI16Gd7tBpeRc9PyM9lB5NBR8HE4TmI_m81vHeXe1NOivb7WR4iobirv_E2DBpRssO1evhwCECEpI-MICtQ_KNBpvRo9I5FbhlH9ZZfx8H66hUZMY4fDcBNgLbSmRZFK-T1AGI5D-4SY9gIg2JFdBzB37goqOQh0gsYgAf_n1iGoVHEjtDUQN4euM1_yKY7DAGx5Wnqp2oCefgb5SAV9IJv5EEQaYcsPnjty60vfaewHTOmt7GpvoNTuJUzqmJC4d7BukdN0Llb5MYUfufTiozfTQZyZsRh38mNYmAHxMyJLpHnF71dGKnwxQPmjG4lXSm0J1kL41dbbIbGN9rzpm0rzY967-49XQpOo6nWVOorhmaLirOnlB4BRmFVaDfGSBUaoor_zB4M-stv9rrNe5HpggpAc5KamB9nlvHP3eIqNf2T51f4pE-vGEkaLMSPXddkBIFcFjjGROj1cwGW0npcdmYDK2mjorkKVrB9ebu6SMHcxajw3L_wr0VBzAMmb7vLnWypADO7UISpD0CdOrKi4v9H4L5gVfXHfp7p_St_X1SL_XR4a3yDZlCovHxeonvMWHB0glb3s6HyfBd260Pnbya7mMrkSWJTXOgOQieP91GARbpcyJXPYBiGXKq5Xsm_MkI-SQjChaGFQSqeTnVZfmzWFRFuld1eEzZ6gv7C2eA0nkRkDm6A6udkM7rsneydpzHocOWlRLo7Io4N80QuhAb5F6snzMjRcFHlB1Ndwf_JFXn_cS17ZMBZ9gnAYCIH_fthFajUbr7YjS-kFcw-wOLZUGOAE--c1bYrwa9Pul-yc00nW6llbNqFQzEsEip-lwOGz-R2aeU99IQ_rvQcPRBTX7J2jK1Vwvr-NSAOIlCsm-hB8z4jiQ-DKZ3NWARkmazq5e4cweOlVhLOSJNSDDKDGgxx_G45Yi7XLTAokjQWzkmz0GAV1QzipjCf44HKAY2x8h7Fcx6-3qYoiM-u2ludFLyvZgjCzSH0Rea0XogE6AOnbZY8pssTj_n8Na064DGnQdRaSo6jHxOSGBb74rVR8mAzI2_8lUqA-xxzig3O4Tcf3iKnuOz7vWh6N3wsSB_78cK8DFdwqjMlI5mYjW_SsKJaXfoX1rfzAamFG29hwkz1llaEKMnBclWL4RIbALNqTT7yWHjUIX2mTt1WMUUlhFHur1haIAxp7R4pK5FC1qwj7pFPiP4Njs8PyV1cphCSKx7O7bO6FeN-FyGX29cOeFGB1w3ZXazYVaBwNnlNOC4_utn6urg5RwFEVfHU8e7yxerQoe_brx6t-EjmycpNlE.RGq3Huqz6FTmK7ITn6VD9A'  # `__Secure-next-auth.session-token` cookie from https://chat.openai.com/chat

api = ChatGPT(session_token)

# Directory where the LeetCodeTasks folder is located
base_dir = 'Good'
base_dir_test = 'Tests'

# Helper function to extract the numeric prefix from the folder name
def sort_key(folder_name):
    num_part = folder_name.split('_')[0]
    return int(num_part)  # Convert to integer for correct numeric sorting

# Get a sorted list of directories in base_dir
sorted_dirs = sorted(os.listdir(base_dir), key=sort_key)

sorted_dirs = sorted_dirs[1:2]
NUM = 0
# Iterate over each task folder inside the base directory
for task_dir in sorted_dirs:
    task_path = os.path.join(base_dir, task_dir)
    if os.path.isdir(task_path):
        NUM += 1
        print(f"Processing task in folder: {task_path} {NUM}")
        
        # Read the content of task.md
        task_md_path = os.path.join(task_path, 'task.md')
        try:
            with open(task_md_path, 'r') as file:
                task_content = file.read()
        except FileNotFoundError:
            print(f"task.md not found in {task_path}")
            continue
        
        # Iterate over the 'solutions' subdirectory
        solutions_dir = os.path.join(task_path, 'solutions')
        lang_path = os.path.join(solutions_dir, 'python3')
        if os.path.isdir(lang_path):
            # Determine the correct file extension based on the directory name                
            template_path = os.path.join(lang_path, f'template.py')
            test_folder_dir = os.path.join(base_dir_test, task_dir)
            os.makedirs(test_folder_dir, exist_ok=True)
            solution_path = os.path.join(test_folder_dir, f'test.py')
            
            # Read the content of the template file
            try:
                with open(template_path, 'r') as file:
                    template_content = file.read()
            except FileNotFoundError:
                print(f"Template file not found in {lang_path}")
                continue
            
            # Generate GPT query using task_content and template_content
            prompt = (f"Language: Python3\n"
                        f"Task: {task_content}\n"
                        f"Template: {template_content}\n"
                        f"I have solved this task, and I need tests in order to check if my solution is correct.\n"
                        f"Please provide me Python testing suit, which will import my solution and check it.\n"
                        f"Please provide just the final testing code for this task, without any additional information.\n"
                        f"p.s. Do not forget to include/import all the necessary libraries.\n"
                        f"p.s. My solution with name solution.py will be in the same folder as the test script")
            response = api.send_message(prompt)
            api.reset_conversation()
            time.sleep(1)
            
            # Write the GPT response to the solution file
            try:
                with open(solution_path, 'w') as file:
                    file.write(response['message'])
                print(f"Solution written to {solution_path}")
            except Exception as e:
                print(f"Failed to write solution to {solution_path}: {e}")
