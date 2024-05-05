import json
import time
import warnings

import pandas as pd
import requests

from ._constants import NO_PYTHON_STUB, PREMIUM_CUSTOMER_PYTHON_STUB
from ._helper import camel_case
from .models import Question

# Leetcode's graphql api endpoint
BASE_URL = "https://leetcode.com/graphql"


class GetQuestion:
    """
    A class to acquire the statement, constraints, hints, basic test cases, related questions, and code stubs of the given question.

    Args:
        titleSlug (str): The title slug of the question.
    """

    def __init__(self, titleSlug: str):
        self.titleSlug = titleSlug
        self.questions_info = self.fetch_all_questions_id_and_stub()

    @staticmethod
    def fetch_all_questions_id_and_stub():
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36',
        }
        req = requests.get("https://leetcode.com/api/problems/all/", headers=headers).json()
        question_data = pd.json_normalize(req["stat_status_pairs"]).rename(
            columns={
                "stat.frontend_question_id": "QID",
                "stat.question__title_slug": "titleSlug",
            }
        )[["QID", "titleSlug"]]

        return question_data.sort_values("QID").set_index("titleSlug")

    def scrape(self) -> Question:
        """This method calls the Leetcode graphql api to query for the hints, companyTags (currently returning null as this is a premium feature), code snippets, and content of the question.

        Raises:
            ValueError: When the connection to Leetcode's graphql api is not established.

        Returns:
            QuestionInfo: Contains the QID, titleSlug, Hints, Companies, Similar Questions, Code stubs, and the body of the question.
        """
        data = {
            "query": """query questionHints($titleSlug: String!) {
                question(titleSlug: $titleSlug) {
                    questionFrontendId
                    title
                    hints
                    difficulty
                    companyTags {
                        name
                        slug
                        imgUrl
                    }
                    topicTags {
                        name
                    }
                    similarQuestions
                    codeSnippets {
                        lang
                        langSlug
                        code
                    }
                    content
                    isPaidOnly
                }
            }
        """,
            "variables": {"titleSlug": self.titleSlug},
        }
        response = requests.post(BASE_URL, json=data)
        if response.status_code == 404:
            raise ValueError("Leetcode's graphql API can't be found.")
        while response.status_code == 429 | 400:
            time.sleep(10)
            response = requests.post(BASE_URL, json=data)
            if response.status_code == 404:
                raise ValueError("Leetcode's graphql API can't be found.")
        response = response.json()
        return Question(
            QID=response["data"]["question"]["questionFrontendId"],
            title=response["data"]["question"]["title"],
            titleSlug=self.titleSlug,
            difficulty=response["data"]["question"]["difficulty"],
            Hints=response["data"]["question"]["hints"],
            Companies=response["data"]["question"]["companyTags"],
            topics=[
                topic["name"] for topic in response["data"]["question"]["topicTags"]
            ],
            isPaidOnly=response["data"]["question"]["isPaidOnly"],
            Body=self._get_question_body(response),
            Code=self._get_code_snippets(response),
            SimilarQuestions=self._get_similar_questions(response),
        )

    def _get_question_body(self, response) -> str:  # type: ignore
        if not response["data"]["question"]["isPaidOnly"]:
            return response["data"]["question"]["content"]
        else:
            warnings.warn("This questions is only for paid Leetcode subscribers.")
            return "This questions is only for paid Leetcode subscribers."

    # Similar questions
    def _get_similar_questions(self, response) -> list[int]:
        """A helper method to extract the list of similar questions of the
        given question.

        Returns:
            list[int]: The list of QIDs of the questions similar to the given question.
        """
        similar_questions = []
        for qs in json.loads(response["data"]["question"]["similarQuestions"]):
            similar_questions.append(self.questions_info.loc[qs["titleSlug"]].QID)
        return similar_questions

    # Code Snippet


    def _get_code_snippets(self, response) -> dict:
        """A helper method to extract the code snippets for multiple languages from the query response.
        This method returns code snippets for Java, C++, C, and Python3 if available.

        Returns:
            dict: A dictionary containing code snippets for Java, C++, C, and Python3.
        """
        if not response["data"]["question"]["isPaidOnly"]:
            languages = ["java", "cpp", "c", "python3"]
            code_snippets = {}

            for lang in languages:
                # Find the code snippet for the current language
                snippet = [
                    code["code"]
                    for code in response["data"]["question"]["codeSnippets"]
                    if code["langSlug"] == lang
                ]

                if snippet:
                    code_snippets[lang] = snippet[0]
                else:
                    # Provide a default stub if no snippet is found
                    code_snippets[lang] = f"No code snippet available for {lang}."

            return code_snippets
        else:
            warnings.warn("This question is only for paid subscribers.")
            # You could also return stubs for each language if needed
            return {lang: "Premium content. Please subscribe to access." for lang in ["java", "cpp", "c", "python3"]}

