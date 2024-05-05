import unittest
from typing import Optional, List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Function to convert a list to a linked list
def list_to_linkedlist(lst: List[int]) -> Optional[ListNode]:
    if not lst:
        return None
    head = ListNode(lst[0])
    current = head
    for val in lst[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

# Function to convert a linked list to a list
def linkedlist_to_list(head: Optional[ListNode]) -> List[int]:
    lst = []
    current = head
    while current:
        lst.append(current.val)
        current = current.next
    return lst

# Test suite for the solution
class TestSolution(unittest.TestCase):
    def setUp(self):
        # Import the Solution class from solution.py
        from solution import Solution
        self.solution = Solution()

    def test_delete_duplicates(self):
        test_cases = [
            ([1, 2, 3, 3, 4, 4, 5], [1, 2, 5]),
            ([1, 1, 1, 2, 3], [2, 3]),
            ([1, 2, 3, 4, 5], [1, 2, 3, 4, 5]),
            ([], []),
            ([1, 1], [])
        ]
        for input_list, expected_output in test_cases:
            head = list_to_linkedlist(input_list)
            result = self.solution.deleteDuplicates(head)
            self.assertEqual(linkedlist_to_list(result), expected_output)

if __name__ == '__main__':
    unittest.main()
