#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) return 0; // When needle is empty, return 0 as per problem statement.
        
        int n = haystack.length();
        int m = needle.length();
        
        if (m > n) return -1; // Needle is longer than haystack, so it cannot be found.
        
        for (int i = 0; i <= n - m; ++i) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i; // Found the needle in the haystack
            }
        }
        return -1; // Needle not found
    }
};
