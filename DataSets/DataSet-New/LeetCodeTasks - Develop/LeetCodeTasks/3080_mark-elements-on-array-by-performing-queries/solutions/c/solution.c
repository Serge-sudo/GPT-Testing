#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    int index;
    int marked;
} Element;

int elementCompare(const void *a, const void *b) {
    Element *elem1 = (Element *)a;
    Element *elem2 = (Element *)b;
    if (elem1->value == elem2->value) {
        return elem1->index - elem2->index;
    }
    return elem1->value - elem2->value;
}

int indexCompare(const void *a, const void *b) {
    Element *elem1 = (Element *)a;
    Element *elem2 = (Element *)b;
    return elem1->index - elem2->index;
}

long long* unmarkedSumArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    long long *result = (long long *)malloc(queriesSize * sizeof(long long));
    if (!result) return NULL;

    Element *elements = (Element *)malloc(numsSize * sizeof(Element));
    if (!elements) {
        free(result);
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        elements[i].value = nums[i];
        elements[i].index = i;
        elements[i].marked = 0;
    }

    // Sorting elements by value and index for easier management of "smallest unmarked elements"
    qsort(elements, numsSize, sizeof(Element), elementCompare);

    long long totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    int markedCount = 0;
    for (int i = 0; i < queriesSize; i++) {
        int queryIndex = queries[i][0];
        int k = queries[i][1];
        
        // Mark the element at queryIndex if not already marked
        if (!elements[queryIndex].marked) {
            elements[queryIndex].marked = 1;
            totalSum -= nums[queryIndex];
            markedCount++;
        }

        // Mark the smallest `k` unmarked elements
        int markedFromQuery = 0;
        for (int j = 0; j < numsSize && markedFromQuery < k; j++) {
            if (!elements[j].marked) {
                elements[j].marked = 1;
                totalSum -= elements[j].value;
                markedCount++;
                markedFromQuery++;
            }
        }

        result[i] = totalSum;
    }

    free(elements);
    return result;
}
