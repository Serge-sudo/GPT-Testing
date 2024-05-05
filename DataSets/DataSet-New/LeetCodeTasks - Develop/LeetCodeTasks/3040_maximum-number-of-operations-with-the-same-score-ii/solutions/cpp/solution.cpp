#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        unordered_map<int, int> scoreMap;
        int n = nums.size();

        // Calculate possible scores from pairs and populate scoreMap
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                int scoreFirstTwo = nums[i] + nums[i + 1];
                scoreMap[scoreFirstTwo]++;
            }
            if (i > 0) {
                int scoreLastTwo = nums[i - 1] + nums[i];
                scoreMap[scoreLastTwo]++;
            }
            int scoreFirstLast = nums[0] + nums[n - 1];
            scoreMap[scoreFirstLast]++;
        }

        // Adjust counts as each pair would be counted twice for each of their occurrences in the loop
        for (auto& pair : scoreMap) {
            pair.second /= 2;
        }

        // Find the score with the maximum number of operations
        int maxOperations = 0;
        for (const auto& pair : scoreMap) {
            maxOperations = max(maxOperations, pair.second);
        }

        return maxOperations;
    }
};
