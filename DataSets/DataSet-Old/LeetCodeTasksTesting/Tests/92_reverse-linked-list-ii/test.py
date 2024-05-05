# test_solution.py
import unittest
from solution import Solution
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __eq__(self, other):
        if not isinstance(other, ListNode):
            return False
        return self.to_list() == other.to_list()

    def to_list(self):
        lst = []
        current = self
        while current:
            lst.append(current.val)
            current = current.next
        return lst

    @staticmethod
    def from_list(lst):
        if not lst:
            return None
        head = ListNode(lst[0])
        current = head
        for val in lst[1:]:
            current.next = ListNode(val)
            current = current.next
        return head

class TestSolution(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def test_reverse_between(self):
        tests = [
            {"head": [1, 2, 3, 4, 5], "left": 2, "right": 4, "expected": [1, 4, 3, 2, 5]},
            {"head": [5], "left": 1, "right": 1, "expected": [5]},
            {"head": [1, 2, 3, 4], "left": 1, "right": 2, "expected": [2, 1, 3, 4]},
            {"head": [1, 2, 3, 4], "left": 3, "right": 4, "expected": [1, 2, 4, 3]},
            {"head": [1, 2, 3, 4, 5], "left": 1, "right": 5, "expected": [5, 4, 3, 2, 1]},
        ]
        for test in tests:
            head = ListNode.from_list(test["head"])
            left, right = test["left"], test["right"]
            expected = ListNode.from_list(test["expected"])
            result = self.sol.reverseBetween(head, left, right)
            self.assertEqual(result, expected)

if __name__ == '__main__':
    unittest.main()
