#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> result;
        int s_len = s.length(), a_len = a.length(), b_len = b.length();

        // Vectors to store the starting indices where substrings a and b are found
        vector<int> indices_a;
        vector<int> indices_b;

        // Find all occurrences of substring a in s
        for (int i = 0; i <= s_len - a_len; ++i) {
            if (s.substr(i, a_len) == a) {
                indices_a.push_back(i);
            }
        }

        // Find all occurrences of substring b in s
        for (int i = 0; i <= s_len - b_len; ++i) {
            if (s.substr(i, b_len) == b) {
                indices_b.push_back(i);
            }
        }

        // Check each index i for a if there is any j for b such that |i - j| <= k
        for (int i : indices_a) {
            for (int j : indices_b) {
                if (abs(i - j) <= k) {
                    result.push_back(i);
                    break;
                }
            }
        }

        return result;
    }
};
