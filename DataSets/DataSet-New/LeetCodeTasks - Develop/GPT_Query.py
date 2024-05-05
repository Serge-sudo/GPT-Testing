import os
from Libs.pychatgpt import ChatGPT
import time
# Set up your session token for ChatGPT API
session_token = 'eyJhbGciOiJkaXIiLCJlbmMiOiJBMjU2R0NNIn0..V9NMmXcr2b9VnXqE.NiV7jGqChauJd6zHsgnk5nxHSGKy2-S1PEHjz44FDWxTP3K7Q_KDlVav8qfLmxN_TDhgfSgzQSpMWbqTMMdwrHsmWWr1yiLg4oxny5jjK8jBbva1H0PbDU5WxwCtBjhsHqAT9dPlJIbwcXFDG-Y7QVJXO5asf1KSsQhn69zEsVzlNZGh6-hcOpONNsP4S2cC1GEtdqqW8GSFKROBzQiwDmuTgFKqXoxG7-rCLm_Wuz8gt9Ehz02s1g3r2rByvb4zR8YBjc5chzGyd_vzTSp2840EBXL2XGHC3eFgxB-aU4pxGyNXKpyj_QTY2t3Qdx6hTGTKZSj2pTYpJDvIj4jq2Bc5me5l8fjMnCHcdKn-4wPXlFlT1pq6EsNauScoSJekueXRBSMxoZjEkLAh-aRQmUnMT5Rmdct0jNcyeUo7A-rlIYUCzCLkMpsfmW6M6EwPRd6KEkH7NTdludIrpWschG1PkN-bF7acxwsb0yEyMZwLD_RRoA16a1cWnunysukLf3a646T4_vXEtPZXv_OP9AU8LctPoPuEW-7AFS3YgVGkPRG4akWdPC9yrTNpyzDHy0Xw2ccpFGf7P7x-8e7BUgAMdJbfwO_ByvtQgNEDvO-jEYoRkAZb-ZGQ_E1dJq5P74iiUdgjvQ5x7IkWO-OU_D0ASLkfXhBhh_PQr6MDiaNXXwixCHJQcq-EsYkgtKae0Kn5He3z7MK2pg06Ac_vHcQeuAV4mGUhLMmOJKV18nw3FvUVSsaa1NEaNHRHMIPv8tEK_nD_UPA90VqMQwmwJcECtvNCYwHPfqY1oZl96L9b0UXKkIlL5EtnzOvHesYUTrZpYAjdfQYGNovn3gHQs8Sf6xoH9ZfF7rw-HfRqXx_NVYy-qoc3mXpMRDTPbPrpfwEPFCbV6H0xwAOnmAFF7zrob-yjmiB_0YYd5-5dgOHhO12PEWieIv5F4WBEzqGW610ixYO_bD0JEPemfb7BpRm8aY7ZI0L69miOKaGNZXGtTxCcsalbKA6rDTT-_k1GYmcyJXgqJtHP_KiodZMV9AG_vTb3G9HlCPhM7Rrhth7PXaq63aayKdb6XGIs5bI2VR2W5nk2stYhaZOTOD8HMlp7-RkJj1ouyLAK4_3DaF5PK9rZdIvDzrl9erL-R9Hi_F053pGMXycjYwu6J6lIAbfJW0_OWqE5mhwSSdeSn7_Emm1mLtraCjr6kMPacrn7_-27HYqurHv05PG54FpOdRwzNvpNs-WCj6RkwC7Z73GW88FIweikRi-Rjm28QAYU6SYNbTTUz6IHlZkNhb9Owg9iTpnsSE0omo7fdybNAPFKjRgtD0aY08_ur3wNzy1eWBxn7b3Jf38RuETDWiTBaRJpCPNb3OPg5CBjeBomomDV1SoLThwpcObxfT8zI3HvXYwpxePQ08G1jf3DlCzXx88Hykx7nFfokxhpIDsaQ1QZWdy2aIHQazPYvK3G0EBvbVX9x_PBvrZafsbVjUxNcxegJJLOUybH0QbwFXU6Ax4SrciWX1ojeJcL20M9jvn3gVd2snsnNgPq_-wX8muz1VanDk3gwiKm9mE7K5F0VdhMMVzGs1g44xHzAgLdZMFtPM4-7iI9gB543xtPjYqyDGvCs7A_oAfcXYyj14woQMVU0YqyReyKlqOMLjpwy4AhNXUaBoh0Vpf5tGFbqifk8KEjAyABb3hkua6ptb-qds-aoGMSr5wMeDyt5iV4K4t9VYkQl3s1YJRze4QmRfTCb3u5bNfy4QnSWXmd2mYjJb7--DoB8N8qzJIo9Jay9JLJYAzzXPOlCWy1blR5MhT2s_6yDYknmvsxtuFsgaWcE4YEXOakEey651Op12Ug6uwiZIX_W0pC7QfrXgTzlk2jbJLzBJhc6IMwz2-28Zq65rRCSktOUXoKL9n7n51Y5GA360uWiP6SxLWBf4HI18oWhoRdsEaQZPvAoS-ATM1DmrJlzNOt1tj6CDoY3L8pIpm1pT7yGR8Hiedvd8n1sI1M5Fsty-k7U0FhiDZPfPBaDeJJb-PuVnRsWSxLj0v3K5pqTR462KNsm9zPcEbKOKDATbk9lv19Fku2bPvn1wsXQqnq4RYYjFMV9qvI9nbsy0YrCTACAuo7rsjtUfRBP27-nG_70otWMAnK_ZRARVTv8PuhGIKoGRcW0zf1Ymh4k91uFhLJ3p0OLs5qLv98r2kjjuXvFRWOxSJoTC7-0QYJuR_IKA04qDCIOoMPotBQmQmkew6RhqgGtDRRTGLXM93LbGvTHB1H60-6sjEQ-CszUlfIypjn6dTUhPigDV_eKxAUtFt9_cwX5GhhJQDWFvhJg3mc41wiYoEwoDIbh2rNN5wvqWtt3sONpwz8sUkGYsx-l3aXrMFhUk7iIg4z56lrixYxdwAkI4cmPr3QeS8FzCiCj2ah76-sDhNeoQ8Z_cmwcnmI3HaaomFe7rC4Kcq49TbqRuv4HGFqs8PhFrNEiJLkbByrwCkM3vuJ7YjVqBvXOkHoLoKhNAbumJsy-NWwvCpyi03U942n0BgbCv9hxXecY3IMF7Ynv84-hxtk2GMO83lDENHOHGAa3u8k3UmbPJD7RJ0yLFPgk7GshB5aLyb937HszPNZ0dFFY98eQOfejTXFJsqEAb-UnnpGFvmupBcsFrU7Z9t8MJvT-wqOgBzCzdX5Oks3SyzVG7FHiH6TkUmulM6NHc66Pgw85_4B2YTWB5zJcVkvhEH1sWa343nZTBblN-llhfi8xsihefskf8zJDTPm6N9wmp24CPDNGMHkp4HMJjnqTcW-KGi3uV9p7a9VQFxmQavnTYj__zsOngk93b4OIO5vTBcDZV6f57yWxoa-GBA_jOeCCVOo996ApruejBksYU4Ms1901P0Vn6qHbtgSB7fiq7Qzalddi3d3o-8Lx4oOurr2w6sAtuchhJLnukReUD6fUbtz8ig9B3bZMjo-Jrnb-n5XoblXdlQPEQcWVJeKpIQHiEeE5uZSO7GQyvDKARzmFKuyqTTSDMHFtGprmOaOEyyaR-UhcgCtvtcwqnNSf-K7c0LUbnqxXN12RFifGkeh00Ktbh0dQxpETo5taT0usqu3AbRN0fkH.iTwX8ezaQO_P20KklFaRsw'  # `__Secure-next-auth.session-token` cookie from https://chat.openai.com/chat

api = ChatGPT(session_token)

# Directory where the LeetCodeTasks folder is located
base_dir = 'LeetCodeTasks'

# Helper function to extract the numeric prefix from the folder name
def sort_key(folder_name):
    num_part = folder_name.split('_')[0]
    return int(num_part)  # Convert to integer for correct numeric sorting

# Get a sorted list of directories in base_dir
sorted_dirs = sorted(os.listdir(base_dir), key=sort_key)

sorted_dirs = sorted_dirs[85:86]
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
