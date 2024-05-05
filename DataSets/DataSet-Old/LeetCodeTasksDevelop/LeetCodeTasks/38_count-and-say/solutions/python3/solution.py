class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        
        def say(sequence):
            result = ""
            i = 0
            while i < len(sequence):
                count = 1
                while i + 1 < len(sequence) and sequence[i] == sequence[i + 1]:
                    i += 1
                    count += 1
                result += str(count) + sequence[i]
                i += 1
            return result
        
        current = "1"
        for _ in range(1, n):
            current = say(current)
        
        return current
