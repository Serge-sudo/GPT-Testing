#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> freq(26, 0);
        // Fill frequency for known characters
        for (char c : s) {
            if (c != '?') {
                freq[c - 'a']++;
            }
        }

        // Replace '?' with the lexicographically smallest character that minimizes the value
        for (char& c : s) {
            if (c == '?') {
                for (int i = 0; i < 26; i++) {
                    if (freq[i] == 0) { // Find the smallest unused character
                        c = 'a' + i;
                        freq[i]++;
                        break;
                    }
                }
            }
        }

        return s;
    }
};
