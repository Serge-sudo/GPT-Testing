#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size();
        int len_a = a.size();
        int len_b = b.size();
        
        vector<int> indices_a;
        vector<int> indices_b;
        
        // Find all occurrences of a in s
        for (int i = 0; i <= n - len_a; ++i) {
            if (s.substr(i, len_a) == a) {
                indices_a.push_back(i);
            }
        }
        
        // Find all occurrences of b in s
        for (int i = 0; i <= n - len_b; ++i) {
            if (s.substr(i, len_b) == b) {
                indices_b.push_back(i);
            }
        }
        
        vector<int> result;
        // For each index of a, check for proximity of any index of b
        for (int i : indices_a) {
            bool found = false;
            for (int j : indices_b) {
                if (abs(j - i) <= k) {
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
