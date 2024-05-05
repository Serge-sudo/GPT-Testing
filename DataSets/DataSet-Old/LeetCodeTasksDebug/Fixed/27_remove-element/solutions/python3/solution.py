class Solution:

    def removeElement(self, nums: list[int], val: int) -> int:
        k = 0  # Start k at 0 to handle the empty or no valid case properly

        for num in nums:
            if num != val:
                nums[k] = num
                k += 1

        return k
