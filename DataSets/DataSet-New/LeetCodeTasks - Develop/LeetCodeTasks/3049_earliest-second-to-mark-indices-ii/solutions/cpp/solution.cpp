#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();
        
        vector<int> timesToZero(n, INT_MAX); // Tracks the earliest time each index can be zeroed
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map; // Maps index to the seconds it can be set to zero
        
        // Prepare the map of times for each index when it can be set to zero
        for (int i = 0; i < m; i++) {
            int idx = changeIndices[i] - 1; // Convert 1-based to 0-based
            map[idx].push(i + 1); // Push the second (1-based)
        }
        
        // Determine the minimum second each index can be zeroed
        for (int i = 0; i < n; i++) {
            if (!map[i].empty()) {
                timesToZero[i] = map[i].top(); // Earliest second we can zero this index
            }
        }
        
        // Process marking of indices, considering decrement operations
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap: (time, index)
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) { // Already zero, can be marked from second 1
                pq.emplace(1, i);
            } else {
                pq.emplace(timesToZero[i], i); // Can potentially be zeroed later
            }
        }
        
        vector<bool> marked(n, false);
        int maxTime = 0;
        int marksCount = 0;
        
        while (!pq.empty()) {
            auto [time, idx] = pq.top();
            pq.pop();
            
            if (marked[idx]) continue; // If already marked, skip
            
            if (time == INT_MAX) { // If time is still INT_MAX, we cannot zero this index
                return -1;
            }
            
            // Mark the index
            marked[idx] = true;
            maxTime = max(maxTime, time); // Update the latest time we performed a marking
            marksCount++;
            
            if (marksCount == n) { // If all indices are marked
                return maxTime;
            }
        }
        
        return -1;
    }
};
