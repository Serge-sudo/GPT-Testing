#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> indicesA, indicesB, result;
        int lenA = a.size(), lenB = b.size();
        
        // Collect all occurrences of a in s
        for (int i = 0; i <= int(s.length()) - lenA; ++i) {
            if (s.substr(i, lenA) == a) {
                indicesA.push_back(i);
            }
        }
        
        // Collect all occurrences of b in s
        for (int j = 0; j <= int(s.length()) - lenB; ++j) {
            if (s.substr(j, lenB) == b) {
                indicesB.push_back(j);
            }
        }
        
        // For each index in indicesA, check for any valid index in indicesB
        for (int i : indicesA) {
            bool found = false;
            for (int j : indicesB) {
                if (abs(i - j) <= k) {
                    found = true;
                    break;
                }
            }
            if (found) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
