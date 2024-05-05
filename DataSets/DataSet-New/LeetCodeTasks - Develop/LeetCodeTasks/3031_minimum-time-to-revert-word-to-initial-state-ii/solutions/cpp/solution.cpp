#include <string>

class Solution {
public:
    int minimumTimeToInitialState(std::string word, int k) {
        int n = word.size();
        if (n % k == 0) {
            return n / k;
        }
        
        // To calculate the minimum cycle length, we will use the concept of
        // finding the smallest cycle in a permutation induced by rotations.
        // We will consider the sequence of strings we can obtain by performing the
        // operations mentioned, and find when it first repeats.
        
        // Construct the sequence using modular arithmetic
        int current = 0;
        int steps = 0;
        do {
            current = (current + k) % n;
            steps++;
        } while (current != 0);
        
        return steps;
    }
};
