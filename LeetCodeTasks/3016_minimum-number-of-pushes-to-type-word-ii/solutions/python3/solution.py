from collections import defaultdict

class Solution:
    def minimumPushes(self, word: str) -> int:
        keypad = {
            'a': 2, 'b': 3, 'c': 4, 'd': 5, 'e': 6, 'f': 7, 'g': 8, 'h': 9,
            'i': 9, 'j': 0, 'k': 0, 'l': 0, 'm': 0, 'n': 0, 'o': 0, 'p': 0,
            'q': 0, 'r': 0, 's': 0, 't': 0, 'u': 0, 'v': 0, 'w': 0, 'x': 2,
            'y': 3, 'z': 4
        }
        pushes = 0
        prev_key = -1
        for char in word:
            curr_key = keypad[char]
            if curr_key != prev_key:
                pushes += 1
                prev_key = curr_key
        return pushes
