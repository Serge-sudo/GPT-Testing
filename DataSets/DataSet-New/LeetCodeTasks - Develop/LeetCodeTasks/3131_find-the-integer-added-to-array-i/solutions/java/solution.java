class Solution {
    public int addedInteger(int[] nums1, int[] nums2) {
        // As the problem guarantees that there exists an `x` such that nums1 can be transformed into nums2,
        // we can safely take the difference of the first elements of both arrays to find `x`.
        return nums2[0] - nums1[0];
    }
}
