class Solution:

    def minOperations(self, nums: list[int], k: int) -> int:

        nums.sort()

        count = 1

        for num in nums:

            if num <= k:

                count = 1

            else:

                break

        return count

