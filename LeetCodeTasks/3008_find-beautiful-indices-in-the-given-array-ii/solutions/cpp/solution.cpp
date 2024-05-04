#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        int lenA = a.length();
        int lenB = b.length();
        vector<int> indicesA;
        vector<int> indicesB;
        
        // Find all starting indices where a occurs in s
        for (int i = 0; i <= n - lenA; ++i) {
            if (s.compare(i, lenA, a) == 0) {
                indicesA.push_back(i);
            }
        }
        
        // Find all starting indices where b occurs in s
        for (int i = 0; i <= n - lenB; ++i) {
            if (s.compare(i, lenB, b) == 0) {
                indicesB.push_back(i);
            }
        }
        
        vector<int> beautiful;
        int j = 0;

        // Process all indices where a occurs
        for (int idxA : indicesA) {
            // Move the pointer for b's indices to the minimum value that might be within range
            while (j < indicesB.size() && indicesB[j] < idxA - k) {
                j++;
            }
            
            int tempJ = j;
            // Check within range k to the right and left
            while (tempJ < indicesB.size() && indicesB[tempJ] <= idxA + k) {
                if (abs(indicesB[tempJ] - idxA) <= k) {
                    beautiful.push_back(idxA);
                    break;
                }
                tempJ++;
            }
        }
        
        return beautiful;
    }
};
