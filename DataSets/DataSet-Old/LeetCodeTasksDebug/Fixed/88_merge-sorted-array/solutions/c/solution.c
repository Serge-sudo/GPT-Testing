#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1; // Last valid element of nums1
    int j = n - 1; // Last element of nums2
    int k = m + n - 1; // End of merged array

    while (j >= 0) {
        if (i >= 0 && nums1[i] >= nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
}
