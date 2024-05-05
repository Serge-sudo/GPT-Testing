#include <string>
#include <unordered_map>

class Solution {
public:
    int maximumLengthSubstring(string s) {
        std::unordered_map<char, int> charCount;
        int maxLen = 0;
        int start = 0;

        for (int end = 0; end < s.length(); ++end) {
            charCount[s[end]]++;

            while (charCount[s[end]] > 2) {
                charCount[s[start]]--;
                start++;
            }

            maxLen = std::max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};
