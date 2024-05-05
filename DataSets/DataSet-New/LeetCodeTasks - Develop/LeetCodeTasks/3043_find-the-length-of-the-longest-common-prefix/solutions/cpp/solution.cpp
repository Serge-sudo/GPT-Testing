#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
        // Convert all numbers in arr1 and arr2 to strings
        std::vector<std::string> str1(arr1.size()), str2(arr2.size());
        std::transform(arr1.begin(), arr1.end(), str1.begin(), [](int num) { return std::to_string(num); });
        std::transform(arr2.begin(), arr2.end(), str2.begin(), [](int num) { return std::to_string(num); });

        // Sort string representations to use binary search later
        std::sort(str1.begin(), str1.end());
        std::sort(str2.begin(), str2.end());

        int longest = 0;
        
        // Function to find longest common prefix length between two strings
        auto commonPrefixLength = [](const std::string& s1, const std::string& s2) {
            int len = std::min(s1.length(), s2.length());
            for (int i = 0; i < len; i++) {
                if (s1[i] != s2[i]) {
                    return i;
                }
            }
            return len;
        };
        
        // Check each string in str1 against all in str2 using binary search for efficiency
        for (const std::string& s1 : str1) {
            auto it = std::lower_bound(str2.begin(), str2.end(), s1);
            if (it != str2.end()) {
                longest = std::max(longest, commonPrefixLength(s1, *it));
            }
            if (it != str2.begin()) {
                longest = std::max(longest, commonPrefixLength(s1, *std::prev(it)));
            }
        }
        
        return longest;
    }
};
