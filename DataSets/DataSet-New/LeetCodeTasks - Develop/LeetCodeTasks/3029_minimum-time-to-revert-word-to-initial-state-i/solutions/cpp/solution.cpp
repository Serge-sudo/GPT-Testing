#include <string>
using namespace std;

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        if (k == n) return 1; // Special case where the whole string is rotated
        
        // To calculate the minimum time to return to the original string
        // we use the concept of a cycle in the rotations.
        // Each time we rotate k elements to the end, the positions move cyclically.
        
        // Find the cycle length
        int cycleLen = k;
        while (cycleLen % n != 0) {
            cycleLen += k;
        }
        return cycleLen / n;
    }
};
