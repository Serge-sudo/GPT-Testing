import os
from pychatgpt import ChatGPT

# Set up your session token for ChatGPT API
session_token = 'eyJhbGciOiJkaXIiLCJlbmMiOiJBMjU2R0NNIn0..snHQ7Pvn7lsIQsSW.tH0hxuNilF2KwIg5eZ5lEfMMkRZ2gWe8h0O12sKp3nwChrd1aKmXTkw_ClSCviBs9H0yzXsbt200MAvRHqak9tLSXxbJK6uB8TV063Jy5a4hJoVfzNyzVHP6gT7LmwZo4OWli0reDuog_SMv4kr6h-reJG2JobRlzJpFKF6h5aRD9RHN-a6RGk7v9ofiHrghUQsI5y8GRAhrzmKVh1oUqnlNkzzYdg-XK1V5PUSL16Pjh3RSWYnN9MC48PuG0vHcX0fuvCMJM1_wXMRxBgkNr30vK6Pd0wVW877NiHtfiXZZh_tBoQ_LMZS-BS4IFmCchzZwbU-Mz-LCksrvGz8gvNhr_m1d0JspwWQsAYE144F5pxMlGs9KYFdf6NK8v6cBmgcmQgmAg6gqzLVPH9oSCCSssSgTevcKIpALAUrgHxNoSBrcwYvgcHFydZYaxeoCVtQizKlwuvo5GPoL6fm_ke83BpQof3u3ffsiHNOF4fkidYElbPjrk_ugMjJWtDVZGxR9AHuBhoLlaArjFKQmyHNJiLbaV3b_DJAHkLyTb4lGfcka9YNijh33zxpSgV4OH-3KzKm2DkIy17YBvdgL052C4iTSg4l4fxE03oVVrj1SdeZ0RznkwixhQv4QisNSwQ5Eb3oTzdyZ9naKh6KeeHJq7b-OechmrZFyGo3jHt51iaRQAhbo7azO1kWyJY4ngVkF1JPZyICL8I9L82jSmvrlY1SS5ioWhJARPXdiGEcFA-IPy4QI3W3w5nYibcJuEfmugZjz7sDwcNBr1FxiVwf5P95zqRrcjvjO7l_O_-el2WogOI3tNY-2r7ycxsqtrAnXCePVfXANDdm4XYnfG9ASnMCqvGF05sjw3jcrfRfFkqVB4i3Kqa8R3xqw6gVDodKqm9-wkwBE3J2__-IV3JldRMOq9-hU0k3tm_quJO2dVnVTwN9UfRSHZjJhdJOv7X4ZvM2wIvbEZI_UFeRdAzYbNjpVm5Pefz7izRxOkyh5F_nDTW_SOOuPz4I30Zg15Ky3cIdsQa8QNrOIc_g_aEFsXLtjp-ke3tkHm-a-Jqo21YeCdOkprFXAOL4HccBfmw5_lPnTG7CyBs8eevoKnqor7x2NeSPF6Gd6PVfGC_xDj_Mhru4IWmvv_VHiwtfDJ5BdPqjGpBUuuF5ecoSTgjl_6_sRKD_UV0ejmgWd7h4Is3XIlIaGGCtaCd4XjqS78G0PTHydMTM1Pa2xo-9d75G66Ih166TaF5w4lVeGtd8cBexEUde_dH3NY0MMN2rWxq-2dH9s2_JrGA3WQGxYLXQ-B0PIxb7TAUP2g2r0t6y2gnmX8v7kjOtA_4qzrLNE271KIn_E-sVHaT4nBA-9OAPBYnuvwLvaXMRzwfL9_JsfOyvgxXbCcXOHzx4gDLLcOlc3UVJGmZ3cc4lXxnJvKS9NJgUb0QfaGa3EGcdeQ4l5vTCCLqqqEJf2PYSUxCY2DHjQwRfhLD5u2USmMp2IvJABQRm84Exd2z2HODCHzk2qQ_cVP5xC6ZvVXSBKELHlNSlCfYa1ee1OQwYJaK9xerM_EzaVuW7ZKEfx44IBd_al-3SvY_q1PUvNKVykAZqmTf97RRsZJ8FHhh5nn5E8Cfjko3d_Fmjwoj0oQjfsS7du8Hug0LQ5y3T-Tnn12Orw_yCPxaHOsJg_rkY9Fo7AfRygTySfohtYaJxjLTSpc9Ze67gewIvTpcn0Bl50byh7g14UOGkVa1-28mrrg-37J9sERaRONop3CyHkqffitLYiP4JC3JlaW3GEhzYW_WzLMW_xA2Pcf7OWb-0fPxGf12y1djUT5mZG5Mj0K89hXjkXgWCBhhYYrWFpPaQ_jhP92M2Kj3bLu-ts3-QbYcAllyDRBN6ubr2_hevxNbWjlZ9K8Dg7u8ijzym02e-vyBWR4pElC9f8D72ImnKETbVQB_brbpuS93OzWHN_3COWL0NBe9EHTVpqlcnhHDpKc1Sc0pbVMqKdAVsICz2Vi9KvRo7uHZRV4aY0iY-3LiDWEWXE_52BVzZUARwGEMJaxsLdaiSEhR4-n1QQ2VnbWu21G2EaTDRkoBaXDixnVrqmKHaisj9FTKPh_s4Vu94njz0sImJzduUPcO9nKDeR4XOqs2z6YR_DZEewA69dMz1Wg9zo7il8P1_iHA22tcqBKeyS2YRqE2SFXQi4gScPBTf0OYnfofREOhb-O4w7pYuMguUzolFOxqgiDrjjwzNZfcTYw2fO1oI0O1w8lcnNjpZeYgRNHs49Xj7jVrDDrniZWIBErGfLpqg-iSao3D7tj7SBFlAW1A7UOL2-PTSD7i0OlDz8thbb5Lli4l-c0BXZA7ewItLcZ61_uosI3cPlM3nL6kO2Zi2VaW1tZwkj_Uh-MDhgJE03mF5sOs9EiIY50IT9Et6uerLjDa2wJwIb8l_MzFjWeG1Ha9Rs_2g-lKghuUmHPoT9dOlenpvSXOLNLK0rkw7gyxwrizA6A9t9_BqNrw9trlZLg2fyoFhBksNW7O6xdE_yRjIPZrD9g9Sk8cBV3ZBs0HXTeTUOLOgHN9aVUS2Tqztj8iNy6g0k-U9w1MH45iKJUxiFLwis-hoPO2Aek9Z4rOhB5Uk4nmTW_FiI-KOE07KXIyZIVQSRvjWci8EeZZaXUvEUkkkVKx2I4qaLdrFbMtoTok1chhNBRJYAd91enmkYIXevVSNALx-mhk75xYJutspUo-NrFXIP2zR-ihlna-vfN8zXr4ARhMEtH6ksjLjpOFXbdg8lCUzch-L1cmrW5Y0SZHYJP2w_Yqw6xRQArDJXrfmeO4psK6eIRrB5EXe5Cj6kRFmde5_0wTinGTO5N4tZyK5o6NzO-y_hFTJHQXqkMrXTiEImvuMiIy2C21csSQBFyEDanEtyX2C1-rVO-qOF0jptR3BptLCWLZfhoHNlNh6OQLdTNHDkVeDLPK_WYnSjww.m_XO7l_9G8Mo8ualtu96Dw'  # `__Secure-next-auth.session-token` cookie from https://chat.openai.com/chat

api = ChatGPT(session_token)

# Directory where the LeetCodeTasks folder is located
base_dir = 'LeetCodeTasks'

# Helper function to extract the numeric prefix from the folder name
def sort_key(folder_name):
    num_part = folder_name.split('_')[0]
    return int(num_part)  # Convert to integer for correct numeric sorting

# Get a sorted list of directories in base_dir
sorted_dirs = sorted(os.listdir(base_dir), key=sort_key)


# Iterate over each task folder inside the base directory
for task_dir in sorted_dirs:
    task_path = os.path.join(base_dir, task_dir)
    if os.path.isdir(task_path):
        print(f"Processing task in folder: {task_path}")
        
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
                
                # Write the GPT response to the solution file
                try:
                    with open(solution_path, 'w') as file:
                        file.write(response['message'])
                    print(f"Solution written to {solution_path}")
                except Exception as e:
                    print(f"Failed to write solution to {solution_path}: {e}")
