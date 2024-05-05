import re

class Solution:
    def isNumber(self, s: str) -> bool:
        pattern = r'^[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?$'
        return re.match(pattern, s) is not None
