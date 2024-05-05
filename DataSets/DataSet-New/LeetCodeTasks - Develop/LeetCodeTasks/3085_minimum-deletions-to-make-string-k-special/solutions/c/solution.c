#include <string.h>
#include <stdlib.h>

int minimumDeletions(char* word, int k) {
    int freq[26] = {0};
    int n = strlen(word);
    
    // Count the frequency of each character
    for (int i = 0; i < n; i++) {
        freq[word[i] - 'a']++;
    }
    
    // Count how many characters have each frequency
    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }
    
    int *freqOfFreq = (int *)calloc(maxFreq + 1, sizeof(int));
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            freqOfFreq[freq[i]]++;
        }
    }
    
    int minDeletions = n;
    for (int targetFreq = 1; targetFreq <= maxFreq; targetFreq++) {
        int currentDeletions = 0;
        int minValidFreq = targetFreq - k;
        int maxValidFreq = targetFreq + k;
        
        // Sum deletions needed to bring freqs below minValidFreq to minValidFreq
        for (int freq = 1; freq < minValidFreq; freq++) {
            if (freqOfFreq[freq] > 0) {
                currentDeletions += freq * freqOfFreq[freq];
            }
        }
        
        // Sum deletions needed to bring freqs above maxValidFreq to maxValidFreq
        for (int freq = maxValidFreq + 1; freq <= maxFreq; freq++) {
            if (freqOfFreq[freq] > 0) {
                currentDeletions += (freq - maxValidFreq) * freqOfFreq[freq];
            }
        }
        
        // Update minimum deletions if the current scenario is better
        if (currentDeletions < minDeletions) {
            minDeletions = currentDeletions;
        }
    }
    
    free(freqOfFreq);
    
    return minDeletions;
}
