import unittest
from solution import Solution

class TestMergeSortedArrays(unittest.TestCase):
    def test_example1(self):
        nums1 = [1, 2, 3, 0, 0, 0]
        m = 3
        nums2 = [2, 5, 6]
        n = 3
        Solution().merge(nums1, m, nums2, n)
        self.assertEqual(nums1, [1, 2, 2, 3, 5, 6])

    def test_example2(self):
        nums1 = [1]
        m = 1
        nums2 = []
        n = 0
        Solution().merge(nums1, m, nums2, n)
        self.assertEqual(nums1, [1])

    def test_example3(self):
        nums1 = [0]
        m = 0
        nums2 = [1]
        n = 1
        Solution().merge(nums1, m, nums2, n)
        self.assertEqual(nums1, [1])

    def test_no_elements_in_nums2(self):
        nums1 = [1, 2, 3, 4, 0, 0, 0]
        m = 4
        nums2 = []
        n = 0
        Solution().merge(nums1, m, nums2, n)
        self.assertEqual(nums1[:m], [1, 2, 3, 4])

    def test_no_elements_in_nums1(self):
        nums1 = [0, 0, 0, 0]
        m = 0
        nums2 = [2, 3, 4, 5]
        n = 4
        Solution().merge(nums1, m, nums2, n)
        self.assertEqual(nums1, [2, 3, 4, 5])

    def test_larger_arrays(self):
        nums1 = [1, 3, 5, 7, 0, 0, 0, 0]
        m = 4
        nums2 = [2, 4, 6, 8]
        n = 4
        Solution().merge(nums1, m, nums2, n)
        self.assertEqual(nums1, [1, 2, 3, 4, 5, 6, 7, 8])

if __name__ == "__main__":
    unittest.main()
