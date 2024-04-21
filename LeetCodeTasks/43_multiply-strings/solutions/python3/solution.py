class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        
        # Result can be at most len(num1) + len(num2) in length
        res = [0] * (len(num1) + len(num2))
        
        # Reverse both numbers to simplify position tracking
        num1, num2 = num1[::-1], num2[::-1]
        
        # Multiply each digit from num1 with each digit from num2
        for i in range(len(num1)):
            for j in range(len(num2)):
                # Multiply the digits
                mul = int(num1[i]) * int(num2[j])
                # Add to the appropriate position in result
                res[i + j] += mul
                # Carry over to the next position
                res[i + j + 1] += res[i + j] // 10
                res[i + j] %= 10
        
        # Remove leading zeros and convert list to string
        while res[-1] == 0:
            res.pop()
        
        return ''.join(map(str, res[::-1]))
