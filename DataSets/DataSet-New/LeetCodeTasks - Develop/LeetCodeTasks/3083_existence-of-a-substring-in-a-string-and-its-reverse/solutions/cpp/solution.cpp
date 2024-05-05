#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> substrings;
        int n = s.length();
        
        // Collect all substrings of length 2 in the original string
        for (int i = 0; i < n - 1; ++i) {
            substrings.insert(s.substr(i, 2));
        }
        
        // Check if any substring from the original is in the reversed string
        for (int i = n - 1; i > 0; --i) {
            string revSubstr = s.substr(i - 1, 2);
            if (substrings.count(revSubstr)) {
                return true;
            }
        }
        
        return false;
    }
};
