#include <string.h>

int minimumTimeToInitialState(char* word, int k) {
    int n = strlen(word);
    int count = 1;
    
    // Calculate initial remainder (position in string modulo k)
    int remainder = n % k;
    
    // If remainder is 0, it directly cycles back to the start
    if (remainder == 0) return 1;
    
    // Use the remainder to determine the cycling period
    int current_remainder = remainder;
    while (current_remainder != 0) {
        current_remainder = (current_remainder + remainder) % k;
        count++;
    }
    
    return count;
}
