#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int* beautifulIndices(char* s, char* a, char* b, int k, int* returnSize) {
    int s_len = strlen(s);
    int a_len = strlen(a);
    int b_len = strlen(b);
    
    // Result dynamic array and size tracker
    int* result = (int*)malloc(s_len * sizeof(int));
    *returnSize = 0;
    
    // Find all occurrences of 'a' and 'b'
    int* indices_a = (int*)malloc(s_len * sizeof(int));
    int* indices_b = (int*)malloc(s_len * sizeof(int));
    int count_a = 0, count_b = 0;
    
    // Collect indices where 'a' occurs
    for (int i = 0; i <= s_len - a_len; i++) {
        if (strncmp(s + i, a, a_len) == 0) {
            indices_a[count_a++] = i;
        }
    }
    
    // Collect indices where 'b' occurs
    for (int i = 0; i <= s_len - b_len; i++) {
        if (strncmp(s + i, b, b_len) == 0) {
            indices_b[count_b++] = i;
        }
    }
    
    // Check each index in indices_a for the beautiful condition
    for (int i = 0; i < count_a; i++) {
        int idx_a = indices_a[i];
        bool found = false;
        
        for (int j = 0; j < count_b; j++) {
            int idx_b = indices_b[j];
            if (abs(idx_b - idx_a) <= k) {
                found = true;
                break;
            }
        }
        
        if (found) {
            result[(*returnSize)++] = idx_a;
        }
    }
    
    free(indices_a);
    free(indices_b);
    
    return result;
}
