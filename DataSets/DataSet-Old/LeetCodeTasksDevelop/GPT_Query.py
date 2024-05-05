import os
from pychatgpt import ChatGPT
import time
# Set up your session token for ChatGPT API
session_token = 'eyJhbGciOiJkaXIiLCJlbmMiOiJBMjU2R0NNIn0..KDkpCUCUa4HTzGm7.cCwkDiohfTqVn-w5YBsHAlEEF7fHpQEy8NTRP9IDZCEHdcrQSlcMq51U4Pu4itVW9x2u9vnqX18oGHp24Nsz8efpnkd4WsMIL7jAdRtFAUDc38p1sPwgPjCp0i8d_t5Pm5r2bonayLQddkLtuzeB5fkGwn_fceOhGUaoM7e8RR5qGTBgIyBx26suA1DgcxOrzWHrvGMxG2TjQSmGIFfrsPn9TDTV3Pm7YpXnfw3ct_a_ygb24iaywX4gGG1ARFtHEnSLK-BvGY7X3GJ5_pI58Udtr5nyrHoTPlgo_OlvLQemzPJKXV-Hy33L7mWzbVpU7nuLDUBrad1greD2tScxGavQuI_aBVOdrM-NMEISTaluo3X_WrFXIEEoPAfjqZ56midxXKnO0_HOjqzEnSFSBElaZ-on3jZzFKOq0XqZgAbNIr-dFBXzRCoiYdSgxAyNsKX4FaRMak5ColkL8k8Z2zvltEwvEK5Po9gHC7GFs2IsUuFfb2SXk4xrpRfNPZ_5vh6skjZZD3PCt6HcyjwnkbYKGM-x7Dd97S5t6vh2eIct0I_ZAXUT_jMFQF17J_WLI7S4fUODzez6vMiT-u4sqAz1w9UVmbXpAfgdQxZzfUnMwCQUWg1Ye7RceHvmR-ntNhSRws0eOdGQmu8wXk0Iv9hrm8gszWA5nwPtxh4HGqWIvcPbD7Ltsmug9U3PNdcqH5XBrBi4kn6M5AADUKRaRmoquY9d5ETnN312wLMm5mvWv2qXrbHF6JnJaZD0sDloZYwRUvhsupnFhJ0oogviU8TebjpQklTsjireeCOhDSEAxdZgi7H48FzIhqe1LOrOT6mcdel_SxjZ8YDT4lIp5_B9gqVyUkFmm5478Ea9V7xYwfZw_4_PwDsRtYYUSLdZzVi7a8DBPAhbvUT0bNWYK1Z_SpMfIcjtGrL7gxV-JWafjdg2OTgh2EEaN2xUKDTJcqQZxXIzuf3ChVZHq-Qxtlsd-n6DFFHauzTITen5X4ymgRLxh9b0dys3uSVRn04NM9wN_qVKTI6HutseO04PASNQ9SHvxw04sQhIzwcCwgt45Qy0oxTr5tneLdKoc4L6Ja0D7rj6C9Du0J8Dy84kfmJsySKgS8IIpX7hdGma9N6PqhxFLkRQgzPwfhaKMoSTQh5_wgw3B25jnCdL2FhOXXGtP-eitLj10gLvAzlsd-QVeoqARmExabXO-9FxmUxJgGq-nKmc4eIbEeG55JMA3LatKzZLH32jT13oQeDkSk9Ti8pKxp0yNeC5PslECZ_fYnbAm0VoX6RzHdeQ3F6gVmMThBhdmH5M-3hnp7HTq0HvYbkFRvqjJM4aMpihi8d_5opcj7Mo-_vAGIQC1fA13dUKt8LDlznp2VnpcQGeeItiJ0KP4W4jw5rvJM5uPvJMHR30pjur7JttvSPZNylpJ3g1qC8hVdEGaG6NtsL17bhRLB2VY_wvPFU3l9V8g5faEAcAu5roW6AAQ_3R4EKcvM9bW4JRmhXD_NwmraiqGUCR7DEzVDpznw3fH9llRCQgpO9fR0s6hgPxs8_5vu0cuHq3wihJHiUsMd4hG4AY9yVo5Bubt-SYZbmieqSLoHbdd7tOzt5j1H8VObV4_op2V_Ua2EsRN8wWBYhHWgiqwuJhFUhNLA9E_RN70rOQbcGxlWaxi9oKpg0m-liOZ_9h_KJMC7oFtuzCf0l6nUTTEBJRFZyt144Qe4jhLphZVo7ueMB41jy_4gBJFPnmULMG2yrkgOAAcsomqKPz1eNIykHxsMZE_w-gn-nDI6NUiOIGIuRl1gvVeGw-jduNDOFX0HgY-CfFG8VxFx-zKs5IsK73aA2_nG1vTt-45ElwBzOxTZ8F-UOxf7W32rudWD5Joi-3nJh3UXPt5PKPj3ooUGvL_1u38iixlNaauW2hhoiEkiJSq3swV8vLeXqJ4CI2cswBdw8ngt_fesOY65kKFSAONSd6r28QXJFiblZOsiTgctDXyKR1qAWB81GW-MikEVISOr9EgRYtCQCaCaLjQfcx7TiwJ1cwAsoni_NqYT5xe2nuhIgt9MQOLpt0yf3pFCfwizLpl4kI1CS7HG7_UBwzt3sTYqlc3w353ES_Q1B1hknxL7PSwee0RpibRBgGo35wxhnduONupZbYU-hyFwPwODaTUwlANslKksNrYQJjaHDioDzYOIEhmiMfVvIrTgLefpHiF_EE4oPXPje6aDNtQ1g3EgYj6XTg62uAhJu9ACi6Zh51tM-zh69iihj7msOApL9fZ6ELY9k0t_1VVTshOn4sFUtKQDmMnDmbk0ek9eqzmfMBJTAfUohp3x5qDurU2UfcL82mLjua7-tHuVLt1NMsdDOOeve3fDGnzgIAdD76vYE9kcTAUxyV2EbFcOrjhX1SeqnJ_NyO61r0FSlgQrRA8edQzVRU59vPzuSUxzdO4YQ8WQsy8Jx8zCHZIr0hS7Z1cWUYhDIM13IJDVqdwFKwZmubUdaPuci1Z9mDoBwMpgdp0rQv1cQ6lvCDJN85DoLFNkek2qZnVU4uqyQG2XCbERtdrnoqJpuzqpHl4QhPPpmMVYDO_wPINDsUfRbxnfcdwy9t2_-68ZJPl5OYWVmmhSbyBq4kk_g0guHEnXEqM1QkOQZzCidtZbVb9XL8lvBSvlJ_hDEYBbxx7vKhit2tvLuIbyhywK0oeDhmhmv58Szga9Bm6Xe6q38aQjJDILE-bBFiHb3OMedXPD8603ZO7QA9FeMr631Wt-oVrRLS64I2U1s09k6b0O68VRYrYyW-kj83dhEqnuxd0v5UL9W4JQgygsfAI0fSqmcf2s1OzQaoLZmnl4-Lwzs7nsEtvmYOcKfbGZ7xuhkogOMj_ws4Tl50a1JpwxX2xAoZDRJ32HhqVruB__ieVo5s_te5iO7ZPRLTC_msiuA28HaFgpaMh9GSPQ2xkPog_ERGOTb5DUSQIYjZjw.a6V0_XFdZmvB5FkmShuSYQ'  # `__Secure-next-auth.session-token` cookie from https://chat.openai.com/chat

api = ChatGPT(session_token)

# Directory where the LeetCodeTasks folder is located
base_dir = 'LeetCodeTasks'

# Helper function to extract the numeric prefix from the folder name
def sort_key(folder_name):
    num_part = folder_name.split('_')[0]
    return int(num_part)  # Convert to integer for correct numeric sorting

# Get a sorted list of directories in base_dir
sorted_dirs = sorted(os.listdir(base_dir), key=sort_key)

sorted_dirs = sorted_dirs[112:]
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
        for lang_dir in ['c', 'cpp', 'java', 'python3']:
            lang_path = os.path.join(solutions_dir, lang_dir)
            if os.path.isdir(lang_path):
                # Determine the correct file extension based on the directory name
                file_ext = 'py' if lang_dir == 'python3' else lang_dir
                language_name = 'Python' if lang_dir == 'python3' else lang_dir.capitalize()
                
                template_path = os.path.join(lang_path, f'template.{file_ext}')
                solution_path = os.path.join(lang_path, f'solution.{file_ext}')
                
                # Read the content of the template file
                try:
                    with open(template_path, 'r') as file:
                        template_content = file.read()
                except FileNotFoundError:
                    print(f"Template file not found in {lang_path}")
                    continue
                
                # Generate GPT query using task_content and template_content
                prompt = (f"Language: {language_name}\n"
                          f"Task: {task_content}\n"
                          f"Template: {template_content}\n"
                          f"Please provide just the final code for this task, without any additional information.\n"
                          f"p.s. Do not forget to include/import all the necessary libraries.")
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
