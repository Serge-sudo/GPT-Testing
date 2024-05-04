class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        if not nums:
            return 0

        # Initialize the index to store the position of unique elements
        unique_index = 0

        # Iterate over the array starting from the second element
        for i in range(1, len(nums)):
            # If the current element is not equal to the last element in unique list
            if nums[i] != nums[unique_index]:
                # Increment the position for unique element
                unique_index += 1
                # Move the current element to the next position in unique list
                nums[unique_index] = nums[i]

        # Return the length of the unique elements (index + 1 because index starts from 0)
        return unique_index + 1
