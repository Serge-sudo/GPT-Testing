#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maximumSetSize(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);
    
    int keep_count = nums1Size / 2;
    int *counts1 = (int *)calloc(20000001, sizeof(int));
    int *counts2 = (int *)calloc(20000001, sizeof(int));
    int *s = (int *)calloc(20000001, sizeof(int));

    for (int i = 0; i < nums1Size; ++i) {
        counts1[nums1[i]]++;
        counts2[nums2[i]]++;
    }
    
    for (int i = 0; i < nums1Size; ++i) {
        int min_count1 = counts1[nums1[i]] < keep_count ? counts1[nums1[i]] : keep_count;
        int min_count2 = counts2[nums1[i]] < keep_count ? counts2[nums1[i]] : keep_count;
        s[nums1[i]] += min_count1 + min_count2;
        counts1[nums1[i]] -= min_count1;
        counts2[nums1[i]] -= min_count2;
    }
    
    for (int i = 0; i < nums2Size; ++i) {
        int min_count1 = counts1[nums2[i]] < keep_count ? counts1[nums2[i]] : keep_count;
        int min_count2 = counts2[nums2[i]] < keep_count ? counts2[nums2[i]] : keep_count;
        s[nums2[i]] += min_count1 + min_count2;
        counts1[nums2[i]] -= min_count1;
        counts2[nums2[i]] -= min_count2;
    }
    
    int result = 0;
    for (int i = 0; i < 20000001; ++i) {
        if (s[i] > 0) {
            result++;
        }
    }

    free(counts1);
    free(counts2);
    free(s);
    
    return result;
}
