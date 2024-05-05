import java.util.*;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // If nums1 length is greater than nums2, then we will swap the arrays to ensure nums1 is the smaller array.
        if (nums1.length > nums2.length) {
            int[] temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }

        int m = nums1.length;
        int n = nums2.length;
        int imin = 0, imax = m, halfLen = (m + n + 1) / 2;
        
        while (imin <= imax) {
            int i = (imin + imax) / 2;
            int j = halfLen - i;
            
            if (i < imax && nums2[j - 1] > nums1[i]) {
                // i is too small, must increase it
                imin = i + 1;
            } else if (i > imin && nums1[i - 1] > nums2[j]) {
                // i is too big, must decrease it
                imax = i - 1;
            } else { // i is perfect
                int maxLeft = 0;
                if (i == 0) { maxLeft = nums2[j - 1]; }
                else if (j == 0) { maxLeft = nums1[i - 1]; }
                else { maxLeft = Math.max(nums1[i - 1], nums2[j - 1]); }
                
                if ((m + n) % 2 == 1) { return maxLeft; }

                int minRight = 0;
                if (i == m) { minRight = nums2[j]; }
                else if (j == n) { minRight = nums1[i]; }
                else { minRight = Math.min(nums2[j], nums1[i]); }

                return (maxLeft + minRight) / 2.0;
            }
        }
        
        return 0.0; // This line would never be reached.
    }
}
