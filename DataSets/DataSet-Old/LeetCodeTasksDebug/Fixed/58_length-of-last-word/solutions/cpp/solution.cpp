#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int length = 0;
        int n = s.size();
        
        // Start from the end of the string
        int i = n - 1;
        
        // Ignore trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        // Count the length of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length;
    }
};
