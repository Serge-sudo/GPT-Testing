class Solution:

    def countAlternatingSubarrays(self, nums: list[int]) -> int:

        n = len(nums)

        result = 0

        length = 0

        

        for i in range(1, n):

            if nums[i] == nums[i - 1]:

                length += 1

            else:

                result += length + (length + 1) // 2

                length = 1

        

        result += length * (length + 1) / 2

        

        return result

