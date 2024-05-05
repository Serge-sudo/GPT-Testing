#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();

        // Stores the latest second when each index can be marked.
        vector<int> markTime(n + 1, -1);
        
        // Decrement simulation for each index from the changeIndices.
        vector<int> counts(n + 1, 0);
        for (int i = 0; i < m; ++i) {
            counts[changeIndices[i]]++;
            if (nums[changeIndices[i] - 1] <= counts[changeIndices[i]]) {
                markTime[changeIndices[i]] = i + 1;
            }
        }
        
        // Check the availability of all indices to be marked
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] > counts[i]) {
                // If we don't have enough operations to bring nums[i-1] to zero, impossible to mark
                return -1;
            }
            if (markTime[i] == -1) {
                // If we never could mark this index, it's impossible
                return -1;
            }
        }
        
        // Return the maximum of mark times which is the earliest second when all indices are marked
        return *max_element(markTime.begin() + 1, markTime.end());
    }
};
