class Solution:
    def search(self, nums: list[int], target: int) -> bool:
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = (left + right) // 2
            
            if nums[mid] == target:
                return True
            
            # If left part is sorted
            if nums[left] < nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            # If right part is sorted
            elif nums[mid] < nums[right]:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                # Handle duplicates when elements at mid, left, and right are same
                if nums[left] == nums[mid] == nums[right]:
                    left += 1
                    right -= 1
                # If left part is all duplicates
                elif nums[left] == nums[mid]:
                    left = mid + 1
                # If right part is all duplicates
                elif nums[mid] == nums[right]:
                    right = mid - 1
        
        return False
