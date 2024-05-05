#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> freq;
            int distinct_count = 0;
            for (int j = i; j < n; ++j) {
                if (freq[nums[j]] == 0) {
                    distinct_count++;
                }
                freq[nums[j]]++;
                result.push_back(distinct_count);
            }
        }
        
        sort(result.begin(), result.end());
        int m = result.size();
        return result[(m - 1) / 2];
    }
};
