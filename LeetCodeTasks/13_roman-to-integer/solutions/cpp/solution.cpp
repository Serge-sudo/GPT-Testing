#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            int value = romanValues[s[i]];
            
            if (i + 1 < n && value < romanValues[s[i + 1]]) {
                total -= value;
            } else {
                total += value;
            }
        }
        
        return total;
    }
};
