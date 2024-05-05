class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int p1 = m - 1; // Pointer for nums1
        int p2 = n - 1; // Pointer for nums2
        int i = m + n - 1; // Pointer for the end of nums1 array

        // Merge in reverse order
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[i--] = nums1[p1--];
            } else {
                nums1[i--] = nums2[p2--];
            }
        }

        // Add remaining elements from nums2 if there are any
        while (p2 >= 0) {
            nums1[i--] = nums2[p2--];
        }
    }
}
