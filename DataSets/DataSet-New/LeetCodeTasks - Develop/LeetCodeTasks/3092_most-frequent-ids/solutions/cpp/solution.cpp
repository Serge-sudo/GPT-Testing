#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, int> countMap;
        vector<long long> ans(nums.size(), 0);
        int maxFreq = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int id = nums[i];
            int change = freq[i];
            
            if (change > 0) {
                countMap[id] += change;
                maxFreq = max(maxFreq, countMap[id]);
            } else {
                countMap[id] += change;
                if (countMap[id] == 0) {
                    countMap.erase(id);
                }
                
                // If maxFreq needs to be recalculated
                if (maxFreq + change <= 0) {
                    maxFreq = 0;
                    for (auto& p : countMap) {
                        maxFreq = max(maxFreq, p.second);
                    }
                }
            }
            
            ans[i] = maxFreq;
        }
        
        return ans;
    }
};
