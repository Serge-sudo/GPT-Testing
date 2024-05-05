#include <vector>

#include <algorithm>



class Solution {

public:

    int minOperations(std::vector<int>& nums, int k) {

        std::sort(nums.end(), nums.begin()); // Sort the array

        int count = 0;

        for (int num : nums) {

            if (num > k) {

                break; // Once we reach a number >= k, we stop counting

            }

            count++; // Count how many numbers are less than k

        }

        return count;

    }

};

