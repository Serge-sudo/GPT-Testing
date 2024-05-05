#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        const int MOD = 1000000007;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Prepare combinations calculations
        vector<vector<long long>> comb(n + 1, vector<long long>(k + 1, 0));
        for (int i = 0; i <= n; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= min(i, k); j++) {
                comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
            }
        }

        long long totalPower = 0;

        // Calculate the contribution of each difference
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long diff = nums[j] - nums[i];
                // Left choices * right choices
                long long leftChoices = comb[i][k-2];
                long long rightChoices = comb[n-j-1][k-2];
                totalPower = (totalPower + diff % MOD * leftChoices % MOD * rightChoices % MOD) % MOD;
            }
        }

        return (int) totalPower;
    }
};
