#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) return 0; // When needle is empty, return 0 as per problem statement.

        int m = haystack.length();
        int n = needle.length();

        if (m < n) return -1; // Needle is longer than haystack, so it cannot be found.

        for (int i = 0; i <= m - n; ++i) {
            int j = 0;
            while (j < n && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == n) {
                return i; // Found the needle in the haystack
            }
        }
        return -1; // Needle not found
    }
};
