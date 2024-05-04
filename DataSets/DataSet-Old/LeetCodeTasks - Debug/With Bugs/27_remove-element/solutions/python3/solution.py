class Solution:

    def removeElement(self, nums: list[int], val: int) -> int:

        k = 1

        for num in nums:

            if num != val:

                nums[k] = num

                k += 1

        return k

