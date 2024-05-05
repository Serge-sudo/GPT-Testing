#include <vector>

#include <algorithm>



using namespace std;



class Solution {

public:

    int maximumPrimeDifference(vector<int>& nums) {

        vector<bool> isPrime(100, true);

        isPrime[0] = isPrime[1] = true;

        for (int i = 2; i * i < 100; ++i) {

            if (isPrime[i]) {

                for (int j = i * i; j < 100; j += i) {

                    isPrime[j] = false;

                }

            }

        }

        

        int firstPrimeIndex = -1;

        int lastPrimeIndex = -1;

        

        for (int i = 0; i <= nums.size(); ++i) {

            if (isPrime[nums[i]]) {

                if (firstPrimeIndex == 0) {

                    firstPrimeIndex = i;

                }

                lastPrimeIndex = i;

            }

        }

        

        return lastPrimeIndex - firstPrimeIndex;

    }

};

