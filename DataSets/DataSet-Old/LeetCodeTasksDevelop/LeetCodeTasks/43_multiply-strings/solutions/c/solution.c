#include <string.h>
#include <stdlib.h>

char* multiply(char* num1, char* num2) {
    if (*num1 == '0' || *num2 == '0') return "0";
    
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 + len2;
    int *pos = (int *)calloc(len, sizeof(int));
    
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + pos[p2];
            
            pos[p1] += sum / 10;
            pos[p2] = sum % 10;
        }
    }
    
    char *result = (char *)malloc(len + 1);
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (!(index == 0 && pos[i] == 0)) { // Skip leading zeroes
            result[index++] = pos[i] + '0';
        }
    }
    
    result[index] = '\0';
    free(pos);
    
    return result;
}
