#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<bool> isPrime(101, true); // Correct size to include 100
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
        
        for (int i = 2; i * i <= 100; ++i) { // Correct upper bound condition
            if (isPrime[i]) {
                for (int j = i * i; j <= 100; j += i) { // Correct upper bound condition
                    isPrime[j] = false;
                }
            }
        }

        int firstPrimeIndex = -1;
        int lastPrimeIndex = -1;

        for (int i = 0; i < nums.size(); ++i) { // Correct iteration bound
            if (isPrime[nums[i]]) {
                if (firstPrimeIndex == -1) { // Correct comparison value
                    firstPrimeIndex = i;
                }
                lastPrimeIndex = i;
            }
        }

        return lastPrimeIndex - firstPrimeIndex;
    }
};
