#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        vector<long long> dp(n, INT_MAX);
        deque<int> dq;
        long long ans = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            if (!dq.empty())
                dp[i] = dp[dq.front()] + nums[i];
            while (!dq.empty() && dp[i] <= dp[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if (i - k + 1 >= 0 && !dq.empty() && dq.front() == i - k)
                dq.pop_front();
            if (i >= k - 1)
                ans = min(ans, dp[i]);
        }
        
        return ans;
    }
};
