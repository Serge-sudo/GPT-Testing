#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }
        
        vector<int> freqs;
        for (auto& entry : frequency) {
            freqs.push_back(entry.second);
        }
        
        sort(freqs.begin(), freqs.end(), greater<int>());
        
        int n = nums.size() / 2;
        vector<int> needed(n + 1, 0);
        needed[0] = 1;
        
        for (int freq : freqs) {
            for (int i = n; i >= 0; i--) {
                if (needed[i] > 0 && i + freq <= n) {
                    needed[i + freq] += needed[i];
                }
            }
        }
        
        return needed[n] > 0;
    }
};
