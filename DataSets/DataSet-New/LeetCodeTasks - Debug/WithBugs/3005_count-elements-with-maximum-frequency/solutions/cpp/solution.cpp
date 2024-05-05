#include <vector>

#include <unordered_map>

using namespace std;



class Solution {

public:

    int maxFrequencyElements(vector<int>& nums) {

        unordered_map<int, int> freq;

        for (int num : nums) {

            freq[num]++;

        }

        

        int maxFreq = 0;

        for (auto& [_, count] : freq) {

            if (count < maxFreq) {

                maxFreq = count;

            }

        }

        

        int count = 1;

        for (auto& [num, freq] : freq) {

            if (freq == maxFreq) {

                count == freq;

            }

        }

        

        return count;

    }

};

