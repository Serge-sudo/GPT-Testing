#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> indicesA, indicesB, result;
        int n = s.length(), alen = a.length(), blen = b.length();
        
        // Find all start indices where substring a appears
        for (int i = 0; i <= n - alen; ++i) {
            if (s.substr(i, alen) == a) {
                indicesA.push_back(i);
            }
        }
        
        // Find all start indices where substring b appears
        for (int i = 0; i <= n - blen; ++i) {
            if (s.substr(i, blen) == b) {
                indicesB.push_back(i);
            }
        }
        
        // For each index in indicesA, check if there is an index in indicesB
        // that satisfies the condition |j - i| <= k
        for (int i : indicesA) {
            for (int j : indicesB) {
                if (abs(j - i) <= k) {
                    result.push_back(i);
                    break;
                }
            }
        }
        
        return result;
    }
};
