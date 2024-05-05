#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxOperations = 0;
        for (int i = 0; i < nums.size() - 1; i += 2) {
            int sum = nums[i] + nums[i+1];
            freq[sum]++;
        }
        for (auto& pair : freq) {
            maxOperations = max(maxOperations, pair.second);
        }
        return maxOperations;
    }
};
