#include <stdbool.h>
#include <ctype.h>

bool isNumber(char* s) {
    bool numSeen = false;
    bool dotSeen = false;
    bool eSeen = false;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            numSeen = true;
        } else if (s[i] == '.') {
            if (eSeen || dotSeen) {
                return false;
            }
            dotSeen = true;
        } else if (s[i] == 'e' || s[i] == 'E') {
            if (eSeen || !numSeen) {
                return false;
            }
            eSeen = true;
            numSeen = false; // Reset numSeen for the number after 'e'/'E'
        } else if (s[i] == '+' || s[i] == '-') {
            // Sign must come after 'e' or at the start
            if (i != 0 && (s[i-1] != 'e' && s[i-1] != 'E')) {
                return false;
            }
        } else {
            return false;
        }
    }
    
    return numSeen;
}
