class Solution:
    def countKeyChanges(self, s: str) -> int:
        changes = 0
        for i in range(1, len(s)):
            if s[i - 1].lower() != s[i].lower():
                changes += 1
        return changes
