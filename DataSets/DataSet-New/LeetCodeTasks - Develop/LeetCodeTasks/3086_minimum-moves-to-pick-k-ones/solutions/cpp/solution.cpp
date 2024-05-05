#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        int n = nums.size();
        vector<int> positions; // Stores the indices of '1' in nums
        
        // Collect positions of all ones in the array
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                positions.push_back(i);
            }
        }
        
        // We need to find the minimum number of moves to collect k ones
        long long result = LLONG_MAX;
        long long windowSum = 0; // sum of distances in the current window of k ones

        // We use a sliding window over the positions of the ones to find the optimal segment
        for (int i = 0; i < k; ++i) {
            // We consider the middle of the window as the initial pick up point
            windowSum += positions[i];
        }
        
        // The median index among the first k ones
        int medianIndex = k / 2;
        long long median = positions[medianIndex];
        // Calculate initial cost based on this median
        long long initialCost = 0;
        for (int i = 0; i < k; ++i) {
            initialCost += abs(positions[i] - median);
        }
        result = initialCost;
        
        // Sliding the window across all valid sets of k '1's in the array
        for (int i = k; i < positions.size(); ++i) {
            // Sliding the window: remove the leftmost one, add the new one
            windowSum += positions[i] - positions[i - k];
            // Recompute median position index and its value in the window
            medianIndex = (i - k + 1) + k / 2;
            median = positions[medianIndex];
            
            // Calculate the new cost
            long long newCost = 0;
            for (int j = i - k + 1; j <= i; ++j) {
                newCost += abs(positions[j] - median);
            }
            // Compare with the current best result
            result = min(result, newCost);
        }
        
        return result;
    }
};
