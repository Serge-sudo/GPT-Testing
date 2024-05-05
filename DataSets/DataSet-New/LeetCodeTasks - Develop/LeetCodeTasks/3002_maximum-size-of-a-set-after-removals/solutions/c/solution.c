#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maximumSetSize(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    qsort(nums1, nums1Size, sizeof(int), cmpfunc);
    qsort(nums2, nums2Size, sizeof(int), cmpfunc);
    
    int n = nums1Size;  // Since nums1Size == nums2Size == n
    int *used1 = (int *)calloc(n, sizeof(int));
    int *used2 = (int *)calloc(n, sizeof(int));
    int i = 0, j = 0;
    
    while (i < n && j < n) {
        if (nums1[i] < nums2[j]) {
            used1[i] = 1;
            i++;
        } else if (nums1[i] > nums2[j]) {
            used2[j] = 1;
            j++;
        } else {
            // nums1[i] == nums2[j]
            i++;
            j++;
        }
    }
    
    // At this point, mark remaining elements as used
    while (i < n) {
        used1[i++] = 1;
    }
    while (j < n) {
        used2[j++] = 1;
    }
    
    // Count how many are used in each array
    int usedCount1 = 0, usedCount2 = 0;
    for (i = 0; i < n; i++) {
        usedCount1 += used1[i];
        usedCount2 += used2[i];
    }
    
    // Compute how many to remove based on 'used' marking
    int toRemove1 = usedCount1 - n / 2;
    int toRemove2 = usedCount2 - n / 2;
    
    // Calculate the number of unique elements in the final set
    int *set = (int *)malloc(2 * n * sizeof(int));
    int setCount = 0;
    
    i = 0, j = 0;
    while (i < n && j < n) {
        if (nums1[i] < nums2[j]) {
            if (toRemove1 < 1 || !used1[i]) {
                set[setCount++] = nums1[i];
            } else {
                toRemove1--;
            }
            i++;
        } else if (nums1[i] > nums2[j]) {
            if (toRemove2 < 1 || !used2[j]) {
                set[setCount++] = nums2[j];
            } else {
                toRemove2--;
            }
            j++;
        } else {
            set[setCount++] = nums1[i];
            i++;
            j++;
        }
    }
    
    while (i < n) {
        if (toRemove1 < 1 || !used1[i]) {
            set[setCount++] = nums1[i];
        } else {
            toRemove1--;
        }
        i++;
    }
    
    while (j < n) {
        if (toRemove2 < 1 || !used2[j]) {
            set[setCount++] = nums2[j];
        } else {
            toRemove2--;
        }
        j++;
    }
    
    qsort(set, setCount, sizeof(int), cmpfunc);
    int uniqueCount = 1;
    for (i = 1; i < setCount; i++) {
        if (set[i] != set[i - 1]) {
            uniqueCount++;
        }
    }
    
    free(used1);
    free(used2);
    free(set);
    
    return uniqueCount;
}
