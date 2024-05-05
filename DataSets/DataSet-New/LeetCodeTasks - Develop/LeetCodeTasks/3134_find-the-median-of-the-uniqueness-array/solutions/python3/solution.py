from typing import List

class Solution:
    def medianOfUniquenessArray(self, nums: List[int]) -> int:
        from collections import defaultdict
        import bisect

        n = len(nums)
        count_dict = defaultdict(int)
        result = []
        
        for start in range(n):
            seen = defaultdict(int)
            for end in range(start, n):
                seen[nums[end]] += 1
                if seen[nums[end]] == 1:  # New unique element in this subarray
                    count_dict[start, end] = count_dict[start, end-1] + 1
                else:
                    count_dict[start, end] = count_dict[start, end-1]
                # Collect the result of number of unique numbers
                result.append(count_dict[start, end])
        
        # Sort result to prepare for median extraction
        result.sort()
        
        # Median calculation
        mid = len(result) // 2
        if len(result) % 2 == 0:
            return min(result[mid-1], result[mid])
        else:
            return result[mid]

# You can create instances of this class and call its methods with the appropriate parameters in your testing environment.
