#include <string>
using namespace std;

class Solution {
public:
    string findLatestTime(string s) {
        // For the first character (hours tens place)
        if (s[0] == '?') {
            // If the second character (hours units place) is 0-3 or '?', the first can be 1
            // Otherwise, it must be 0 because hours cannot be greater than 11
            s[0] = (s[1] >= '0' && s[1] <= '3') || s[1] == '?' ? '1' : '0';
        }
        
        // For the second character (hours units place)
        if (s[1] == '?') {
            // If the first character (hours tens place) is 1, it can go up to 1
            // Otherwise (it can only be 0), it can go up to 9
            s[1] = s[0] == '1' ? '1' : '9';
        }
        
        // For the third character (colon): fixed, no change needed
        
        // For the fourth character (minutes tens place)
        if (s[3] == '?') {
            // Minutes tens place can go up to 5
            s[3] = '5';
        }
        
        // For the fifth character (minutes units place)
        if (s[4] == '?') {
            // Minutes units place can go up to 9
            s[4] = '9';
        }
        
        return s;
    }
};
