import os
import json
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import NoSuchElementException
import time
import pyautogui
import pyperclip

def init_webdriver():
    options = webdriver.ChromeOptions()
    options.add_argument("--disable-notifications")
    options.add_argument('--disable-features=PrivacySandboxSettings4')
    driver = webdriver.Chrome(options=options)
    return driver

def login_to_leetcode(driver, session_token):
    driver.execute_cdp_cmd(
        'Network.setCookie', {
            'domain': '.leetcode.com',
            'path': '/',
            'name': 'LEETCODE_SESSION',
            'value': session_token,
            'httpOnly': True,
            'secure': True,
        }
    )
    # driver.get("https://leetcode.com")
    time.sleep(2)  # wait for the session to be acknowledged

def submit_solution(driver, problem_name, file_path, language):
    url = f"https://leetcode.com/problems/{problem_name}"
    print(url)
    with open(file_path, 'r') as file:
        code = file.read()
    pyperclip.copy(code)
    driver.get(url)
    WebDriverWait(driver, 30).until(
        EC.presence_of_element_located((By.XPATH, '//button[text()="Auto"]'))
    )
    lang_item = driver.find_elements(By.CLASS_NAME, 'fa-chevron-down')[-1]
    lang_item.click()
    new_lang = driver.find_element(By.XPATH, f'//div[text()="{language}"]')
    new_lang.click()
    time.sleep(1)
    WebDriverWait(driver, 30).until(
        EC.visibility_of_element_located((By.CSS_SELECTOR, '.view-lines.monaco-mouse-cursor-text > div'))
    )
    code_input = driver.find_elements(By.CSS_SELECTOR, '.view-lines.monaco-mouse-cursor-text > div')[0]
    code_input.click()
    action = webdriver.ActionChains(driver)
    action.key_down(Keys.CONTROL).send_keys('a').key_up(Keys.CONTROL).perform()
    action.send_keys(Keys.DELETE).perform()
    pyautogui.hotkey('ctrl', 'v')
    action.key_down(Keys.CONTROL).send_keys(Keys.ENTER).key_up(Keys.CONTROL).perform()
    WebDriverWait(driver, 30).until(
        EC.visibility_of_element_located((By.XPATH, '//div[text()="All Submissions"]'))
    )
    time.sleep(3)
    better = dict()
    try: # Accepted
        result = driver.find_element(By.CSS_SELECTOR, 'div.flex.flex-1.flex-col.items-start.gap-1.overflow-hidden > div > span').text
        typ = driver.find_elements(By.CSS_SELECTOR, 'div.flex.w-full.flex-wrap.gap-3 > div > div:nth-child(1)')
        better_than = driver.find_elements(By.CSS_SELECTOR, 'div.flex.w-full.flex-wrap.gap-3 > div > div:nth-child(3) > span.font-semibold')
        pass_cnt = '1 / 1'
        better[typ[0].text] = float(better_than[0].text[:-1])
        better[typ[1].text] = float(better_than[1].text[:-1])
    except NoSuchElementException: #WA
        try:
            result = driver.find_element(By.CSS_SELECTOR, 'div.flex.items-center.justify-between.gap-4 > div > h3').text
            result = "Wrong Answer"
            pass_cnt = driver.find_element(By.CSS_SELECTOR, 'div.flex.items-center.justify-between.gap-4 > div > h3 > div > span').text
        except NoSuchElementException: #TL #RE #CE #ME
            result = driver.find_element(By.CSS_SELECTOR, 'div.flex.w-full.flex-wrap.items-center > span').text  # This might need adjustment based on actual class names
            pass_cnt = driver.find_element(By.CSS_SELECTOR, 'div.flex.w-full.flex-wrap.items-center > div > span').text
    return result, pass_cnt, better

def process_directory(root_dir, driver):
    task_dirs = sorted(os.listdir(root_dir), key=lambda x: int(x.split('_')[0]))
    task_dirs = task_dirs[13:]
    for dir_name in task_dirs:
        results = {}
        problem_name = dir_name.split('_', 1)[1]
        solutions_dir = os.path.join(root_dir, dir_name, 'solutions')
        for lang_folder in os.listdir(solutions_dir):
            file_ext = 'py' if lang_folder == 'python3' else lang_folder
            solution_path = os.path.join(solutions_dir, lang_folder, f'solution.{file_ext}')
            if os.path.exists(solution_path):
                task_lang = 'c++' if lang_folder == 'cpp' else lang_folder
                result, pass_cnt, better = submit_solution(driver, problem_name, solution_path, task_lang.capitalize())
                results[lang_folder] = {'result': result, 'pass_cnt': pass_cnt, 'Runtime': better.get('Runtime'), 'Memory': better.get('Memory')}
    
        with open(os.path.join(root_dir, dir_name, 'result.json'), 'w') as fp:
            json.dump(results, fp, indent=4, sort_keys=True)


# Main execution
session_token = 'eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiNjA2MjU1OSIsIl9hdXRoX3VzZXJfYmFja2VuZCI6ImFsbGF1dGguYWNjb3VudC5hdXRoX2JhY2tlbmRzLkF1dGhlbnRpY2F0aW9uQmFja2VuZCIsIl9hdXRoX3VzZXJfaGFzaCI6IjAzMWYxY2QzNmE4OGVmNTQ2YTIyNGQ3ODQxZTRiODU3NDM3MWY0ODBlYmMyNDI1MTMwMzcxODkwNjhjYmVmMDQiLCJpZCI6NjA2MjU1OSwiZW1haWwiOiJzZXJnZXkuc2FyZ3N5YW4uMjAwMUBnbWFpbC5jb20iLCJ1c2VybmFtZSI6IlNlcmdlXzg4OCIsInVzZXJfc2x1ZyI6IlNlcmdlXzg4OCIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLmNvbS91c2Vycy9kZWZhdWx0X2F2YXRhci5qcGciLCJyZWZyZXNoZWRfYXQiOjE3MTc4NDcyNDAsImlwIjoiOTMuMTc1LjI4LjE0NCIsImlkZW50aXR5IjoiYzkyYmFhZTcxMzE4ZGM4MWRlNTFhNjYzZGYyZjhiNGYiLCJzZXNzaW9uX2lkIjo2MzE0OTE0NywiX3Nlc3Npb25fZXhwaXJ5IjoxMjA5NjAwfQ.qtzRkXYkGjYV8u5Hp2Fwj3IFoaCeReUFRF41OxR6ohA'
driver = init_webdriver()
login_to_leetcode(driver, session_token)
process_directory('LeetCodeTasks', driver)
driver.quit()
