#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    int longestPrefixLength = 0;
    char str1[10], str2[10]; // 10 is sufficient to store digits of numbers up to 10^8
    
    for (int i = 0; i < arr1Size; i++) {
        sprintf(str1, "%d", arr1[i]);
        int len1 = strlen(str1);
        
        for (int j = 0; j < arr2Size; j++) {
            sprintf(str2, "%d", arr2[j]);
            int len2 = strlen(str2);
            
            int currentPrefixLength = 0;
            for (int k = 0; k < len1 && k < len2; k++) {
                if (str1[k] == str2[k]) {
                    currentPrefixLength++;
                } else {
                    break;
                }
            }
            
            if (currentPrefixLength > longestPrefixLength) {
                longestPrefixLength = currentPrefixLength;
            }
        }
    }
    
    return longestPrefixLength;
}
