#include <vector>
#include <queue>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(nums.begin(), nums.end());
        int ops = 0;
        
        while (minHeap.size() > 1 && minHeap.top() < k) {
            int x = minHeap.top();
            minHeap.pop();
            int y = minHeap.top();
            minHeap.pop();
            minHeap.push(x * 2 + y);
            ops++;
        }
        
        return ops;
    }
};
