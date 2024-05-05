#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                ++digits[i]; // Increment the current digit
                return digits;
            }
            digits[i] = 0; // Set to 0 if it's 9
        }
        // If we are here, all digits were 9, so we need to add a leading 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
