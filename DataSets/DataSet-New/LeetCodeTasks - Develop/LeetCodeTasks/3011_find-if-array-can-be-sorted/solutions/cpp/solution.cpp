#include <vector>
#include <algorithm>
#include <unordered_map>
#include <bitset>

class Solution {
public:
    bool canSortArray(std::vector<int>& nums) {
        // Create a map to hold vectors of numbers by their bit count
        std::unordered_map<int, std::vector<int>> countMap;
        
        // Count the set bits and categorize the numbers
        for (int num : nums) {
            int bitCount = std::bitset<5>(num).count(); // maximum bit length needed for max 28 is 5 bits
            countMap[bitCount].push_back(num);
        }
        
        // For each bit count, sort the corresponding list of numbers
        for (auto& pair : countMap) {
            std::sort(pair.second.begin(), pair.second.end());
        }
        
        // Vector to hold the final sorted array from the groups
        std::vector<int> sortedArray;
        sortedArray.reserve(nums.size());
        
        // Insert the numbers from each group into the final sorted array
        for (int i = 0; i <= 28; ++i) { // Considering the maximum number of bits
            if (countMap.find(i) != countMap.end()) {
                sortedArray.insert(sortedArray.end(), countMap[i].begin(), countMap[i].end());
            }
        }
        
        // Compare the newly created sorted array with the original to determine if sorting is possible
        return sortedArray == nums;
    }
};
