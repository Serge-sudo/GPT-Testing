import unittest
from solution import Solution, ListNode

class TestSolution(unittest.TestCase):
    def list_to_linkedlist(self, lst):
        """Helper function to convert a list to a linked list."""
        if not lst:
            return None
        head = ListNode(lst[0])
        current = head
        for value in lst[1:]:
            current.next = ListNode(value)
            current = current.next
        return head

    def linkedlist_to_list(self, head):
        """Helper function to convert a linked list to a list."""
        lst = []
        current = head
        while current:
            lst.append(current.val)
            current = current.next
        return lst

    def test_deleteDuplicates(self):
        solution = Solution()

        test_cases = [
            ([1, 1, 2], [1, 2]),
            ([1, 1, 2, 3, 3], [1, 2, 3]),
            ([], []),
            ([1, 2, 3, 4, 5], [1, 2, 3, 4, 5]),
            ([1, 1, 1, 1, 1], [1]),
            ([1, 2, 2, 2, 3, 3, 4, 5, 5], [1, 2, 3, 4, 5])
        ]

        for input_list, expected_output in test_cases:
            with self.subTest(input_list=input_list, expected_output=expected_output):
                head = self.list_to_linkedlist(input_list)
                result_head = solution.deleteDuplicates(head)
                result_list = self.linkedlist_to_list(result_head)
                self.assertEqual(result_list, expected_output)

if __name__ == "__main__":
    unittest.main()
