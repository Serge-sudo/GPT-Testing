#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Sort happiness values in decreasing order
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long maxHappiness = 0;
        long long sumHappiness = 0;
        
        // Prepare a prefix sum to calculate decrement effects
        vector<long long> prefixSum(happiness.size() + 1, 0);
        for (int i = 0; i < happiness.size(); ++i) {
            prefixSum[i + 1] = prefixSum[i] + happiness[i];
        }
        
        // Calculate the maximum sum possible
        for (int i = 0; i < k; ++i) {
            // Sum from the k highest values so far
            sumHappiness += happiness[i];
            // Every step, the rest of the values are decremented once (up to the remaining unselected)
            long long remainingDecrement = max(0, (int)happiness.size() - i - 1);
            long long totalDecrementEffect = min(remainingDecrement, (long long)k);
            // Calculate decrement effect by subtracting from the sum of all remaining unselected values
            long long decrementEffect = totalDecrementEffect * (prefixSum[happiness.size()] - prefixSum[i + 1]);
            // Consider not letting it go negative
            long long currentHappiness = sumHappiness - decrementEffect;
            maxHappiness = max(maxHappiness, currentHappiness);
        }
        
        return maxHappiness;
    }
};
