#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        int maxFreq = 0;
        for (int num : nums) {
            maxFreq = std::max(maxFreq, ++freq[num]);
        }
        int totalCount = 0;
        for (auto& pair : freq) {
            if (pair.second == maxFreq) {
                totalCount += maxFreq;
            }
        }
        return totalCount;
    }
};
