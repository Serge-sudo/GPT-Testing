#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.length();
        if (k == 1) {
            // Special case: When k is 1, we can partition by every character.
            return n;
        }

        // Function to count partitions given a modified string.
        auto countPartitions = [&](const string& str) {
            int partitions = 0;
            int i = 0;
            while (i < str.length()) {
                unordered_map<char, int> charCount;
                int j = i;
                // Expand the current partition while it has at most k distinct characters.
                while (j < str.length() && (charCount.size() < k || charCount.count(str[j]) > 0)) {
                    charCount[str[j]]++;
                    j++;
                }
                // If we exceed k distinct characters, we stop just before adding the new character.
                if (charCount.size() > k) {
                    j--;
                }
                partitions++;
                i = j;
            }
            return partitions;
        };

        int maxPartitions = countPartitions(s);

        // Try changing each character and calculate the maximum partitions.
        for (int i = 0; i < n; ++i) {
            char original = s[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c != original) {
                    s[i] = c;
                    maxPartitions = max(maxPartitions, countPartitions(s));
                    s[i] = original; // Restore original character.
                }
            }
        }

        return maxPartitions;
    }
};
