import time
import os
from Libs.pychatgpt import ChatGPT
# Set up your session token for ChatGPT API
session_token = 'eyJhbGciOiJkaXIiLCJlbmMiOiJBMjU2R0NNIn0..zYyQxqxyOzMctXe3.bVQooW6scx85Qk0DqqJbuw1fWbhRCdAU-1eFspKg3Q-vWAfCGqzwFsJ5ou3N4zTgpYcxB4_WdVyfkwti9mHrnLTZI_p9SYdnUVwsjmKAofjbUfsoPSqL86rdMtIbqUHVyuKYqOItg0z1F3wiLhAooMW2C7ZuRyxl_yZ435MK8rRT4lIv8ePgtxSDlEGancjKR1JEJWxxh7vTA-Hjl5D7z79G7-VHgjgKrOyn_9n0dgJ4cqlBuIoeRI9kwu0Vpn02ambbhTJk46Rfs06sR7FQ9UZ5qnUTZ-64led-99YO-kUrJV_p1BfFYpc6tfn8lcHavTGAx0_CYfP_sWmMzDunujQh91l364mbY2cqUBxEj4Fr-r-ocoaUxkrTRUhS_KWoQq6fqjP5bu5omoRc7XoLkK8oqkUwqJCYi5zB9GJocDQ4LpC5JuUT8Mvohj3pR-9oBSGkC-PBUbv592swdYOXQn4j9pxf1XtooCVa6XeZL2vZjo1HoE0-k04pRFx2-LpWbE1qSlFszWGWzEMjzv-WZ2MT4MUUm2K0dRhapKQ7yaQXxZ2mgHa39ZmIJB7NHP4RRcFfbPDbYPzg_HcL6R_rgJa5v0w5ObZo4KX5MFcMWh-tijuqWfZv0GBTJ8Fbv_xemsCbwJGzOX359UZs5sWsGsoOJoG3ozFb_aXW_svKxMvTQusg11FN_U_VJoquqDDW1hHie41X67Hdxh8WWGKg5cld-w0y_8lT1uUPMbPuIR9da0CttNs8Et92Yn6mNOyROT6HuVJzg_Z1Y89xhA0UWFeUw7ZSAlDslhvU2WBl3iKQ4EvhekV85jB5KVlnrBM1Jhy_ITD1XmMAgtnK8Jva_HJd7e-ACRnGch_JjXMRwtlRAOF1FkKt4GBy3ichDuTZQ6VvqEziGIQuOQVCShdf0JirrD_LHryGsknsYJXo5tuKvoU1siPjGbVXXoSdL0XjlZdvb0tduaSsD9NQffBeQDCvgXAANI-64bRfrRHpCyqT4IEmZ2t2xltrnwkrz5CiaaRojZfnkTuIFSWImR6dcYB8nnMYBZ7Z2tPG0BcDqHHvW9XXLqJdtQxztS1SgCJFcZAijylHxiQMZvQs-PRmVj7mfOqV5wrT4TW_PKnhAixbZokoqut_8baJV6a8KJxFyutqAg6FowwRmHyX2X2bPXGhPHC9uTN0Io4q3n_sbfEVXrUyXf6NdZMIKGtEUvVwsIM-yEOmLrnJUGN5NQdB7F2WsMAi_Piii-YrSLl5sntqxTmNa5DMFg5qbfbZJ81JE5DAQVX97DTvwZpQ-A6JDAAkxoGTqJB_LNRTsmhy2GiS_86U7fL1fYwcvuNqVixM6dNBov0Y1uGnwej0Eo9SN1OKiUcANG0FRNUrIp_Pp7BepVJau3EAzXd6BMhSsvJlJGOYUA_pcbyloX4WmDtFA_B5M0UwM4iGdJkoAZTC5bmJDav2uj04IUxPnkx6TPJc-g6NsqeS7d5OlIXoLhCb0tVVrwovlScI85P-Yp7EaDBdseBbkOCilZibSjut9s5uOGQrKjyOwMg1n6GpiZHqK6xmwDa9nSACeSw4e0HpYi6FrmdSaJ7Uqm7HmhHkErvC3agiGYzxUGjeW6aapvlH8_Hi8DImvvUHbqS-x3vKGGFIObiXeD7QttCf6NR2Z61i626O-DoKJXRh7ymM8LsgiYh8ZL3PTcRRFFn_IUQD4SOaTf36PvbWkSkI02LnHSr0jTqw9O7Ner293AuWkKtwDfNyJhDue_ss1cl3yOS4Zo6gudO6UYmzxQenvfUYe6G1l8gO0DFGuSR1eZJFgbm5cqqhux3hyj-zSdSbC-jm3ndNyHYem1qrzuHva3DQAGMOElKMVnEJObPB66QLbWRxn2b8-TPY9vsv67T3dqQ3nGHnP_jN2jIy19ZqCi_FbDKfpolj6lCIKsG13CggCwftzECpHnNA63MkFA5t59wVj0Zo9mE-JZbTuTjiU3DB4SV3d9ZiXAuHiW0ENtP_Q7ftLV6TllOmtDG-0uRYb4cUdQ14kFZ_kr2gMWMtyar9Ion_kXztXk_ZtIgCjaXdRHwgmvgAm19EnYPJ8Ut74kVRGCYxDZZ-NbgD9ZrqDnwfUEHo8QvFtOnvdv49G7v_nuY4IZlvRk-Wyj9vszkwRJ759AiJxO6Z0TUl8vFoBMaVEUySs9cEgfKDSTZ1VhB2m_E539iEm5YBpkLDXEm7QICmJxtiPv4gAmKIQzFyCNnW1dnBbisE5qXBqU06Q0P7x3g_SOJIPcQIQtVwO-eRYQcWgVZjpskude_UxsYnolpBitlWIwWMqkjRo5U8uv00jQ0OY-gkuEa7Lff68_BYVo85zttnDZRuQmuIA6TMkw7z737ExrDZ9dN-QgfUagSADYZgwkRN9xwRhkdDETj1A0O_OBZ2608zFAbCcxa-ae2I4-xlNsm0G64j1H-QVsJXzmfZB6oAxnLS1QlZmIPK99mq2BNQmk-FXyvOkATF9gsWYpmvHC4kI-jRpL_tIybfOuISBUhpE3N2iHU-Y6tkj2A6KBuoifWLSEqCCZAjqRcVRDXYltMFQ1m083-eoIpyhry8MC2Vfshc-r60IjkajnNrZct6hPGdXTEQodG8N39Jd2jPW5qi-I45YjYoQOe2qLUyjd4BT6YindQOsAziYJgvdHF8qhtSgSffCcOwyxVncRwIM65F2iynVAb3BK1f9lkMUyi85eOXab8vRa-JtznZLBqptu1DQBT0OOBr8iJJrzi4W0dNyKeCTlLFksYWurCHkTAmlORaKTDAHr5Kqj2PYITGoeyYCB8Tpq1XBL-JuQm1gRR4yNZ3oqvUuFo6iOSOyi732oumSS2FJ5xD4F2Db8S9JJ1iDvfQyWLAuDJqRLUyEQz61buB1_PTVGwoS4mv2Gp6xBke5fSWkoXIuh3QDpGSgjfKj0IrK0Z0jGmZa_eKikU5u7c8avQbfE-3tOXrTU2Qr4Xp5QQZtxYMyxWfKPEqpfrq5NeaiPY4LmBdQxDFLhyXhWpLBm7PJgpRx4UwWukLSgeY8GwqlMXpsqEOgFlLgC0X6IaNjIMn47KT6bGTtiStHNFt4Ue6Y5GFR-brbiUK.6eH3mv6TvaO7Qg3ckGI17g'  # `__Secure-next-auth.session-token` cookie from https://chat.openai.com/chat

api = ChatGPT(session_token)

# Directory where the LeetCodeTasks folder is located
base_dir = 'WithBugs'
base_dir_respond = 'Fixed'

# Helper function to extract the numeric prefix from the folder name
def sort_key(folder_name):
    num_part = folder_name.split('_')[0]
    return int(num_part)  # Convert to integer for correct numeric sorting

# Get a sorted list of directories in base_dir
sorted_dirs = sorted(os.listdir(base_dir), key=sort_key)

sorted_dirs = sorted_dirs[26:]

NUM = 0
# Iterate over each task folder inside the base directory
for task_dir in sorted_dirs:
    task_path = os.path.join(base_dir, task_dir)
    task_path_respond = os.path.join(base_dir_respond, task_dir)
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
        solutions_dir_respond = os.path.join(task_path_respond, 'solutions')
        for lang_dir in ['c', 'cpp', 'java', 'python3']:
            lang_path = os.path.join(solutions_dir, lang_dir)
            lang_path_respond = os.path.join(solutions_dir_respond, lang_dir)
            if os.path.isdir(lang_path):
                # Determine the correct file extension based on the directory name
                file_ext = 'py' if lang_dir == 'python3' else lang_dir
                language_name = 'Python' if lang_dir == 'python3' else lang_dir.capitalize()
                
                respond_path = os.path.join(lang_path_respond, f'solution.{file_ext}')
                solution_path = os.path.join(lang_path, f'solution.{file_ext}')
                
                # Read the content of the template file
                try:
                    with open(solution_path, 'r') as file:
                        solution_content = file.read()
                except FileNotFoundError:
                    print(f"Solution file not found in {lang_path}")
                    continue
                
                # Generate GPT query using task_content and template_content
                prompt = (f"Language: {language_name}\n"
                          f"Task: {task_content}\n"
                          f"Solution: {solution_content}\n"
                          f"Fix the bugs in current solution if there are any, if not just return the same code."
                          f"Please provide just the full final fixed code, without any additional information.\n"
                          f"p.s. In your respond do not remove any wrapper class or included library. Also do not change any function signature or naming")
                response = api.send_message(prompt)
                api.reset_conversation()
                time.sleep(1)
                
                # Write the GPT response to the solution file
                try:
                    with open(respond_path, 'w') as file:
                        file.write(response['message'])
                    print(f"Solution written to {respond_path}")
                except Exception as e:
                    print(f"Failed to write solution to {respond_path}: {e}")
