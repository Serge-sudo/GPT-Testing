class Solution:
    def minimumPushes(self, word: str) -> int:
        from collections import Counter
        
        # Count frequency of each character in the word
        frequency = Counter(word)
        
        # Sort characters based on frequency (most frequent first)
        sorted_chars = sorted(frequency.items(), key=lambda x: x[1], reverse=True)
        
        # Cost array for positions on keypad from 1 to n, where n <= 8 (key '9' can handle more than 3 letters)
        cost = [i for i in range(1, 10)]
        
        # To minimize the total cost:
        # Assign the most frequent letters to the cheapest costs (i.e., 1 push per letter)
        total_pushes = 0
        index = 0
        for char, freq in sorted_chars:
            if index < 8:  # For first 8 characters, we assign them to keys 2 to 9 (one per key)
                total_pushes += cost[index] * freq
                index += 1
            else:  # Remaining characters all go to the last key with cost incrementing by each set of 3
                total_pushes += cost[index] * freq
        
        return total_pushes
