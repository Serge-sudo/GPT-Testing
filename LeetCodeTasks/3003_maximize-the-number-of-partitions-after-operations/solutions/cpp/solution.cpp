#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.length();
        int maxPartitions = 0;
        
        // Helper function to count partitions with no modification allowed
        auto countPartitions = [&](const string& t) {
            int count = 0;
            int l = 0;
            while (l < t.length()) {
                unordered_map<char, int> freq;
                int r = l;
                while (r < t.length() && (freq.size() < k || (freq.size() == k && freq.count(t[r]) > 0))) {
                    freq[t[r]]++;
                    r++;
                }
                l = r; // Move left pointer to right pointer, for next partition
                count++;
            }
            return count;
        };

        maxPartitions = countPartitions(s); // Initially without any changes
        
        // Try changing each character in s to any other character
        for (int i = 0; i < n; ++i) {
            char original = s[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == original) continue;
                s[i] = c;
                maxPartitions = max(maxPartitions, countPartitions(s));
            }
            s[i] = original; // Restore original character
        }
        
        return maxPartitions;
    }
};
