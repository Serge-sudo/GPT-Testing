class Solution:
    def countKeyChanges(self, s: str) -> int:
        changes = 0
        last_key = None
        for char in s:
            if char.islower():
                key = 'lower'
            else:
                key = 'upper'
            if last_key != key:
                changes += 1
                last_key = key
        return max(changes - 1, 0)
