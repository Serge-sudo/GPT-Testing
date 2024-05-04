class Solution:
    def canSortArray(self, nums: list[int]) -> bool:
        from collections import defaultdict
        
        # Map to store numbers based on their bit count
        bit_map = defaultdict(list)
        
        # Populate the map with numbers grouped by their bit count
        for num in nums:
            bit_count = bin(num).count('1')
            bit_map[bit_count].append(num)
        
        # Now sort each list in the map and then flatten them
        # according to sorted bit counts
        sorted_list = []
        for bit_count in sorted(bit_map):
            bit_map[bit_count].sort()
            sorted_list.extend(bit_map[bit_count])
        
        # Compare the newly sorted list with the original list
        return sorted_list == sorted(nums)
