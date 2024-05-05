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
    try: # Accepted
        result = driver.find_element(By.CSS_SELECTOR, 'div.flex.flex-1.flex-col.items-start.gap-1.overflow-hidden > div > span').text
        # better_than = driver.find_element(By.CSS_SELECTOR, 'div.flex.items-center.justify-between.gap-2 > div > div > div > span')
        # span:contains("Beats") + span
        pass_cnt = '1 / 1'
    except NoSuchElementException: #WA
        try:
            result = driver.find_element(By.CSS_SELECTOR, 'div.flex.items-center.justify-between.gap-4 > div > h3').text
            result = "Wrong Answer"
            pass_cnt = driver.find_element(By.CSS_SELECTOR, 'div.flex.items-center.justify-between.gap-4 > div > h3 > div > span').text
        except NoSuchElementException: #TL #RE #CE #ME
            result = driver.find_element(By.CSS_SELECTOR, 'div.flex.w-full.flex-wrap.items-center > span').text  # This might need adjustment based on actual class names
            pass_cnt = driver.find_element(By.CSS_SELECTOR, 'div.flex.w-full.flex-wrap.items-center > div > span').text
    return result, pass_cnt

def process_directory(root_dir, driver):
    task_dirs = sorted(os.listdir(root_dir), key=lambda x: int(x.split('_')[0]))
    task_dirs = task_dirs[15:]
    for dir_name in task_dirs:
        results = {}
        problem_name = dir_name.split('_', 1)[1]
        solutions_dir = os.path.join(root_dir, dir_name, 'solutions')
        for lang_folder in os.listdir(solutions_dir):
            file_ext = 'py' if lang_folder == 'python3' else lang_folder
            solution_path = os.path.join(solutions_dir, lang_folder, f'solution.{file_ext}')
            if os.path.exists(solution_path):
                task_lang = 'c++' if lang_folder == 'cpp' else lang_folder
                result, pass_cnt = submit_solution(driver, problem_name, solution_path, task_lang.capitalize())
                results[lang_folder] = {'result': result, 'pass_cnt': pass_cnt}
    
        with open(os.path.join(root_dir, dir_name, 'result.json'), 'w') as fp:
            json.dump(results, fp, indent=4, sort_keys=True)


# Main execution
session_token = 'eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJzb2NpYWxhY2NvdW50X3NvY2lhbGxvZ2luIjp7ImFjY291bnQiOnsiaWQiOm51bGwsInVzZXJfaWQiOm51bGwsInByb3ZpZGVyIjoiZ29vZ2xlIiwidWlkIjoiMTA1NzgzMzA2NzAzMTM4NjQxNzUyIiwibGFzdF9sb2dpbiI6bnVsbCwiZGF0ZV9qb2luZWQiOm51bGwsImV4dHJhX2RhdGEiOnsiaWQiOiIxMDU3ODMzMDY3MDMxMzg2NDE3NTIiLCJlbWFpbCI6InNlcmdleS5zYXJnc3lhbi4yMDAxQGdtYWlsLmNvbSIsInZlcmlmaWVkX2VtYWlsIjp0cnVlLCJwaWN0dXJlIjoiaHR0cHM6Ly9saDMuZ29vZ2xldXNlcmNvbnRlbnQuY29tL2EtL0FMVi1Valdra1pFVXFIbW9UdGdmOFpDYTBwMGVmaUtDbTVJVzZVanlzdy11VDJaTTlmNVlYeFU9czk2LWMifX0sInVzZXIiOnsiaWQiOm51bGwsInBhc3N3b3JkIjoiITIyNjFYZEhXQmZVV3F5ZWNobkRkMEliVWc2ZDFvTFFoWkh5cFBnYnQiLCJsYXN0X2xvZ2luIjpudWxsLCJpc19zdXBlcnVzZXIiOmZhbHNlLCJ1c2VybmFtZSI6IiIsImZpcnN0X25hbWUiOiIiLCJsYXN0X25hbWUiOiIiLCJlbWFpbCI6InNlcmdleS5zYXJnc3lhbi4yMDAxQGdtYWlsLmNvbSIsImlzX3N0YWZmIjpmYWxzZSwiaXNfYWN0aXZlIjp0cnVlLCJkYXRlX2pvaW5lZCI6IjIwMjQtMDQtMTNUMTI6NTA6MTQuNDQ2WiJ9LCJzdGF0ZSI6eyJuZXh0IjoiL2FjY291bnRzL3NvY2lhbC9zaWdudXAvIiwicHJvY2VzcyI6ImxvZ2luIiwic2NvcGUiOiIiLCJhdXRoX3BhcmFtcyI6IiJ9LCJlbWFpbF9hZGRyZXNzZXMiOlt7ImlkIjpudWxsLCJ1c2VyX2lkIjpudWxsLCJlbWFpbCI6InNlcmdleS5zYXJnc3lhbi4yMDAxQGdtYWlsLmNvbSIsInZlcmlmaWVkIjp0cnVlLCJwcmltYXJ5Ijp0cnVlfV0sInRva2VuIjp7ImlkIjpudWxsLCJhcHBfaWQiOjEsImFjY291bnRfaWQiOm51bGwsInRva2VuIjoieWEyOS5hMEFkNTJOMy1NZmpzd2pKUldrd3RSeThRejRILWRJUW0zZXZZaGhsdC1temEyX0hkN09HNEFzcUFSYmhXWWF0MmJSX1Y1cmN6NHVLZlZwZ3ZoT1hhbktKV2NKc2NpZVc3X3Fsblo0NmZmcUhrQUVXQlpianhCNm04OHJ3RHY2bmh0cG85T1k2LTRQNFBxSThpbWt3c1NHYk1VbXFTTy1wY0JBd2FDZ1lLQWJzU0FSTVNGUUhHWDJNaTRlckdQSGhkN1pkZEVDNUh6bnpjbHcwMTY5IiwidG9rZW5fc2VjcmV0IjoiIiwiZXhwaXJlc19hdCI6IjIwMjQtMDQtMTNUMTM6NTA6MTMuMzg5WiJ9fSwiX2F1dGhfdXNlcl9pZCI6IjYwNjI1NTkiLCJfYXV0aF91c2VyX2JhY2tlbmQiOiJhbGxhdXRoLmFjY291bnQuYXV0aF9iYWNrZW5kcy5BdXRoZW50aWNhdGlvbkJhY2tlbmQiLCJfYXV0aF91c2VyX2hhc2giOiIwMzFmMWNkMzZhODhlZjU0NmEyMjRkNzg0MWU0Yjg1NzQzNzFmNDgwZWJjMjQyNTEzMDM3MTg5MDY4Y2JlZjA0IiwiaWQiOjYwNjI1NTksImVtYWlsIjoic2VyZ2V5LnNhcmdzeWFuLjIwMDFAZ21haWwuY29tIiwidXNlcm5hbWUiOiJTZXJnZV84ODgiLCJ1c2VyX3NsdWciOiJTZXJnZV84ODgiLCJhdmF0YXIiOiJodHRwczovL2Fzc2V0cy5sZWV0Y29kZS5jb20vdXNlcnMvZGVmYXVsdF9hdmF0YXIuanBnIiwicmVmcmVzaGVkX2F0IjoxNzE0NDU5NjQ4LCJpcCI6IjkzLjE3NS4yOC4yMDIiLCJpZGVudGl0eSI6IjVlNzA1MjI2YWNkN2E5N2FhNmVlOTVhYjE4ODYzMmQ2Iiwic2Vzc2lvbl9pZCI6NTk1NTc1NzgsIl9zZXNzaW9uX2V4cGlyeSI6MTIwOTYwMH0.fvyJajQeL7k-lX1gD1lHYmWjLAk0WDLk87ljpmF30Pc'
driver = init_webdriver()
login_to_leetcode(driver, session_token)
process_directory('Fixed', driver)
driver.quit()
