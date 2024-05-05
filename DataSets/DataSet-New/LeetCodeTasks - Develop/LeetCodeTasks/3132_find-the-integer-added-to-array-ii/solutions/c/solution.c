#include <stdio.h>

int minimumAddedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int min_x = 2001; // Initialize min_x to a large number
    // Iterate over all pairs (i, j) to consider nums1[i] and nums1[j] as the removed elements
    for (int i = 0; i < nums1Size; i++) {
        for (int j = i + 1; j < nums1Size; j++) {
            // Calculate the required x for each element in nums2
            int valid_x = 1; // Flag to check if a single x works for all elements in nums2
            int x = nums1[i] - nums2[0]; // Calculate x based on the first element of nums2 and current nums1[i]
            // Check if this x can transform nums1 into nums2 by ignoring nums1[i] and nums1[j]
            for (int k = 0; k < nums2Size; k++) {
                int found = 0; // Flag to check if nums2[k] is found in nums1 adjusted by x
                for (int m = 0; m < nums1Size; m++) {
                    if (m != i && m != j && nums1[m] + x == nums2[k]) {
                        found = 1;
                        break;
                    }
                }
                if (!found) { // If nums2[k] is not found for this x
                    valid_x = 0;
                    break;
                }
            }
            if (valid_x && x < min_x) { // If x is valid and smaller than current min_x
                min_x = x;
            }
        }
    }
    return min_x; // Return the minimum valid x
}
