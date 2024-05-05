#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;

        for (int coin : coins) {
            long long multiple = coin;
            while (multiple <= static_cast<long long>(coin) * k) {
                min_heap.push(multiple);
                if (min_heap.size() > k) min_heap.pop();
                multiple += coin;
            }
        }

        while (min_heap.size() > k) min_heap.pop();

        return min_heap.top();
    }
};
