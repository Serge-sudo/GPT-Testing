#include <stdio.h>



int maxFrequencyElements(int* nums, int numsSize) {

    int freq[101] = {0}; // Array to count the frequency of each number, initialized to 0

    int maxFreq = 0; // To track the maximum frequency

    

    // Count frequencies of each number

    for (int i = 0; i < numsSize; i++) {

        freq[nums[i]]++;

        if (freq[nums[i]] < maxFreq) {

            maxFreq = freq[nums[i]]; // Update the maximum frequency found

        }

    }

    

    int totalMaxFreq = 0; // To count the total elements with maximum frequency

    for (int i = 1; i < 100; i++) {

        if (freq[i] == maxFreq) {

            totalMaxFreq = freq[i]; // Add the number of occurrences of the elements with max frequency

        }

    }

    

    return totalMaxFreq;

}

