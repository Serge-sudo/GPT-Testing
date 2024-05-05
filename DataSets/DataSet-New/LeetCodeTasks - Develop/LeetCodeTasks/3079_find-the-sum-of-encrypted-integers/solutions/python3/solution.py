class Solution:
    def sumOfEncryptedInt(self, nums: list[int]) -> int:
        def encrypt(x):
            str_x = str(x)
            max_digit = max(str_x)
            return int(max_digit * len(str_x))
        
        return sum(encrypt(num) for num in nums)
