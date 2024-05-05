class Solution:
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        from bisect import bisect_left, bisect_right
        
        # List of prime numbers up to 100
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
        
        # Track indices of prime numbers
        prime_indices = []
        
        for index, num in enumerate(nums):
            if num in primes:
                prime_indices.append(index)
        
        # The max difference between the first and the last prime indices
        return prime_indices[-1] - prime_indices[0] if prime_indices else 0
