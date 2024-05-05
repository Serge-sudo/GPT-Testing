class Solution:
    def countMatchingSubarrays(self, nums: list[int], pattern: list[int]) -> int:
        n = len(nums)
        m = len(pattern)
        subarray_size = m + 1
        count = 0
        
        for i in range(n - subarray_size + 1):
            match = True
            for k in range(m):
                if (pattern[k] == 1 and not (nums[i + k + 1] > nums[i + k])) or \
                   (pattern[k] == 0 and not (nums[i + k + 1] == nums[i + k])) or \
                   (pattern[k] == -1 and not (nums[i + k + 1] < nums[i + k])):
                    match = False
                    break
            if match:
                count += 1
        
        return count
