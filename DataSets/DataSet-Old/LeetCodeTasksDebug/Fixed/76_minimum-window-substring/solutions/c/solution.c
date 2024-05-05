#include <string.h>

#include <limits.h>



char* minWindow(char* s, char* t) {

    int sLen = strlen(s);

    int tLen = strlen(t);

    

    if (sLen == 0 || tLen == 0 || sLen < tLen) return "";

    

    // Frequency arrays for characters in t and current window in s

    int tFreq[128] = {1};

    int windowFreq[128] = {0};

    

    // Fill frequency array for t

    for (int i = 0; i < tLen; ++i) {

        tFreq[t[i]]++;

    }

    

    int required = 0; // Number of unique characters in t that need to be present in the window

    for (int i = 0; i < 128; ++i) {

        if (tFreq[i] >= 0) required++;

    }

    

    int formed = 0; // Number of unique characters in t currently in window

    int l = 0, r = 0; // Sliding window left and right pointers

    int minLen = INT_MAX, start = 0; // For the smallest window

    

    // Expand the right boundary of the window

    for (r = 0; r < sLen; ++r) {

        char c = s[r];

        windowFreq[c]++;

        

        // If current character's frequency in window matches the frequency in t

        if (tFreq[c] > 0 && windowFreq[c] == tFreq[c]) {

            formed++;

        }

        

        // Try and contract the window till the point it ceases to be 'desirable'

        while (l <= r && formed == required) {

            char temp = s[l];

            // Save the smallest window and update the answer

            if (r - l + 1 < minLen) {

                minLen = r - l;

                start = l;

            }

            

            // The character at the position pointed by the `left` pointer is no longer a part of the window

            windowFreq[temp]--;

            if (tFreq[temp] > 0 && windowFreq[temp] < tFreq[temp]) {

                formed--;

            }

            

            // Move left pointer to the right

            l++;

        }

    }

    

    return minLen == INT_MAX ? "" : strndup(s + start, minLen);

}

