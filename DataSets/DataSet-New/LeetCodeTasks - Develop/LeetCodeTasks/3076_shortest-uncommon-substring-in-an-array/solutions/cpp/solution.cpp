#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> answer(n, "");
        
        for (int i = 0; i < n; ++i) {
            unordered_set<string> otherSubstrings;
            string current = arr[i];
            
            // Collect all substrings from other strings
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                string other = arr[j];
                int len = other.length();
                
                for (int k = 0; k < len; ++k) {
                    for (int l = 1; l <= len - k; ++l) {
                        otherSubstrings.insert(other.substr(k, l));
                    }
                }
            }
            
            // Find the shortest and lexicographically smallest substring not in otherSubstrings
            int len = current.length();
            string best = "";
            
            for (int start = 0; start < len; ++start) {
                for (int length = 1; length <= len - start; ++length) {
                    string sub = current.substr(start, length);
                    if (otherSubstrings.find(sub) == otherSubstrings.end()) {
                        if (best.empty() || length < best.length() || (length == best.length() && sub < best)) {
                            best = sub;
                        }
                    }
                }
                // Early exit if we've found the smallest possible unique substring
                if (!best.empty() && best.length() == 1) break;
            }
            
            answer[i] = best;
        }
        
        return answer;
    }
};
