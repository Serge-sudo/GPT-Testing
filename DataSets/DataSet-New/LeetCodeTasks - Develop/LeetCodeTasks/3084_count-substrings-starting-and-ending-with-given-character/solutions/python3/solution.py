class Solution:
    def countSubstrings(self, s: str, c: str) -> int:
        positions = [i for i, char in enumerate(s) if char == c]
        total = 0
        for i in range(len(positions)):
            start = positions[i]
            if i == len(positions) - 1:
                end = len(s)
            else:
                end = positions[i + 1]
            total += (end - start) * (start - positions[i - 1] if i > 0 else start + 1)
        return total
