#include <stdlib.h>

int minimumLevels(int* possible, int possibleSize) {
    // Calculating total scores for the array
    int totalScore = 0;
    for (int i = 0; i < possibleSize; i++) {
        totalScore += (possible[i] == 1) ? 1 : -1;
    }
    
    int aliceScore = 0;
    int currentTotal = 0;
    
    for (int i = 0; i < possibleSize - 1; i++) {
        aliceScore += (possible[i] == 1) ? 1 : -1;
        currentTotal += (possible[i] == 1) ? 1 : -1;
        
        int bobScore = totalScore - currentTotal;
        if (aliceScore > bobScore) {
            return i + 1;
        }
    }
    
    return -1;
}
