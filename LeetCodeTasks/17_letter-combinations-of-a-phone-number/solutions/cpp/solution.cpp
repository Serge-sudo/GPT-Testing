#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        static const vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        result.push_back("");  // Initialize result with an empty string to start combinations.

        for (char digit : digits) {
            vector<string> temp;
            const string& candidates = mapping[digit - '0'];
            for (const string& combination : result) {
                for (char letter : candidates) {
                    temp.push_back(combination + letter);
                }
            }
            result.swap(temp);
        }

        return result;
    }
};
