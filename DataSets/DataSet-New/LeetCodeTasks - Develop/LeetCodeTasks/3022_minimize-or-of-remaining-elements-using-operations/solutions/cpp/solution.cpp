#include <vector>
#include <queue>
#include <functional>

class Solution {
public:
    int minOrAfterOperations(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) {
            int result = 0;
            for (int num : nums) {
                result |= num;
            }
            return result;
        }
        
        // Priority queue to store the pairs (OR value, length of segment)
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        
        // Initially, each element is its own segment
        for (int num : nums) {
            pq.push({num, 1});
        }
        
        while (k > 0 && pq.size() > 1) {
            auto first = pq.top(); pq.pop();
            auto second = pq.top(); pq.pop();
            
            // Combine the two smallest segments
            int combined = first.first & second.first;
            pq.push({combined, first.second + second.second});
            k--;
        }
        
        // Compute the final OR of remaining elements in the queue
        int finalOr = 0;
        while (!pq.empty()) {
            finalOr |= pq.top().first;
            pq.pop();
        }
        
        return finalOr;
    }
};
