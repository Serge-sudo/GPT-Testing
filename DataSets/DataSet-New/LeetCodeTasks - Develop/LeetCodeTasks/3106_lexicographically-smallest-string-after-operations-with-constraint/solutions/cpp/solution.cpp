#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k) {
        string t = s; // Initialize t to be same as s
        int n = s.length();
        
        // Helper function to calculate cyclic distance between two characters
        auto cyclicDist = [](char a, char b) -> int {
            return min(abs(a - b), 26 - abs(a - b));
        };

        for (int i = 0; i < n; ++i) {
            // Try to minimize each character to 'a' if possible
            int dist = cyclicDist(s[i], 'a');
            if (k >= dist) {
                t[i] = 'a';
                k -= dist;
            } else {
                // Find the nearest character to s[i] within the remaining budget k
                if (s[i] - k >= 'a') {
                    t[i] = s[i] - k;
                } else if (s[i] + k <= 'z') {
                    t[i] = s[i] + k;
                } else {
                    // Calculate nearest by accounting for cyclic nature
                    int leftDist = (s[i] - 'a' + k) % 26;
                    int rightDist = (s[i] - 'a' - k + 26) % 26;
                    if (leftDist < rightDist) {
                        t[i] = 'a' + leftDist;
                    } else {
                        t[i] = 'a' + rightDist;
                    }
                }
                k = 0; // All budget is used
            }
            if (k == 0) break; // If no budget left, stop processing
        }
        
        return t;
    }
};
