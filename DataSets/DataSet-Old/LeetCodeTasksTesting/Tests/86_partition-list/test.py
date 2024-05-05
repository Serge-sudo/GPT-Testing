# Import necessary libraries
import unittest
from solution import Solution, ListNode

# Helper function to convert list to linked list
def list_to_linked_list(lst):
    if not lst:
        return None
    head = ListNode(lst[0])
    current = head
    for value in lst[1:]:
        current.next = ListNode(value)
        current = current.next
    return head

# Helper function to convert linked list to list
def linked_list_to_list(head):
    lst = []
    while head:
        lst.append(head.val)
        head = head.next
    return lst

# Unit testing class
class TestPartition(unittest.TestCase):
    def test_partition(self):
        solution = Solution()

        # Test cases
        cases = [
            ([1, 4, 3, 2, 5, 2], 3, [1, 2, 2, 4, 3, 5]),
            ([2, 1], 2, [1, 2]),
            ([1, 1, 1], 2, [1, 1, 1]),
            ([3, 2, 1], 2, [1, 3, 2]),
            ([5, 8, 3, 6, 7], 4, [3, 5, 8, 6, 7]),
            ([], 1, [])
        ]

        for input_list, x, expected in cases:
            input_head = list_to_linked_list(input_list)
            result_head = solution.partition(input_head, x)
            result_list = linked_list_to_list(result_head)
            self.assertEqual(result_list, expected)

# Execute the tests
if __name__ == '__main__':
    unittest.main()
