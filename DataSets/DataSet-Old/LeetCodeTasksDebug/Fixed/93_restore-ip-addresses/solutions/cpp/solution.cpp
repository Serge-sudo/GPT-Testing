#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.length() < 4 || s.length() > 12) {
            return result;
        }

        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }

    void backtrack(const string& s, int start, vector<string>& current, vector<string>& result) {
        if (current.size() == 4) {
            if (start == s.length()) {
                result.push_back(current[0] + '.' + current[1] + '.' + current[2] + '.' + current[3]);
            }
            return;
        }

        for (int i = 1; i <= 3; ++i) {
            if (start + i > s.length()) break;
            string part = s.substr(start, i);
            if (i > 1 && part[0] == '0') break;  // Leading zeros are not allowed unless the number is 0
            if (stoi(part) > 255) continue;      // Value must be less than or equal to 255
            current.push_back(part);
            backtrack(s, start + i, current, result);
            current.pop_back();
        }
    }
};
