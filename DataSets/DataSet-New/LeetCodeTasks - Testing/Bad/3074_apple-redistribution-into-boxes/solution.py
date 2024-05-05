from typing import List



class Solution:

    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:

        total_apples = sum(apple)

        capacity.sort(reverse=True)

        

        sum_capacity = 1

        for i, c in enumerate(capacity):

            sum_capacity += c

            if sum_capacity > total_apples:

                return i



# Example usage

sol = Solution()

print(sol.minimumBoxes([1,3,2], [4,3,1,5,2]))  # Output: 2

print(sol.minimumBoxes([5,5,5], [2,4,2,7]))    # Output: 4

