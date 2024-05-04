#include <string>

#include <vector>



class Solution {

public:

    std::string getPermutation(int n, int k) {

        std::string result;

        std::vector<int> factorial(n, 1);

        std::vector<char> numbers(n);

        

        // Precompute factorials and number list

        for (int i = 1; i < n; i++) {

            factorial[i] = factorial[i] * i;

        }

        for (int i = 0; i < n; i++) {

            numbers[i] = '1' + i;

        }

        

        k--;  // Convert k from 1-based index to 0-based index for easier calculation.

        

        // Build the k-th permutation using the factorial number system

        for (int i = n - 1; i >= 0; i--) {

            int idx = k / factorial[i];

            result += numbers[idx];

            numbers.erase(numbers.begin() + idx);

            k /= factorial[i];

        }

        

        return result;

    }

};

