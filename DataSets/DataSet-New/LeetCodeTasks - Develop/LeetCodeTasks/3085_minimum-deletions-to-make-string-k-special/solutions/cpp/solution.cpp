#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumDeletions(std::string word, int k) {
        std::unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }

        // Collect all frequencies in a vector
        std::vector<int> frequencies;
        for (const auto& p : freq) {
            frequencies.push_back(p.second);
        }

        // Sorting frequencies
        std::sort(frequencies.begin(), frequencies.end());

        int n = frequencies.size();
        int min_deletions = INT_MAX;

        // Calculate prefix sums for quick range sum calculations
        std::vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + frequencies[i - 1];
        }

        // Try to adjust each frequency so all frequencies are within [freq[i] - k, freq[i] + k]
        for (int i = 0; i < n; ++i) {
            int targetLow = std::max(0, frequencies[i] - k);
            int targetHigh = frequencies[i] + k;

            // Find the last index where frequencies[j] <= targetHigh
            int highIndex = std::upper_bound(frequencies.begin(), frequencies.end(), targetHigh) - frequencies.begin();
            int lowIndex = std::lower_bound(frequencies.begin(), frequencies.end(), targetLow) - frequencies.begin();

            // Calculating deletions needed
            int deletions = 0;
            // Remove excess from the lower part
            if (lowIndex > 0) {
                deletions += (prefixSum[lowIndex] - (targetLow * lowIndex));
            }
            // Remove excess from the upper part
            if (highIndex < n) {
                deletions += ((prefixSum[n] - prefixSum[highIndex]) - (targetHigh * (n - highIndex)));
            }

            min_deletions = std::min(min_deletions, deletions);
        }

        return min_deletions;
    }
};
