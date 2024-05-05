#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        long long num = 1;
        long long accumulatedPrice = 0;
        
        while (true) {
            // Calculate the price of `num` using bit positions x, 2x, 3x, ...
            int price = 0;
            for (int mult = x; mult <= 64; mult += x) {
                if (num & (1LL << (mult - 1))) {
                    price++;
                }
            }
            
            // Add this price to the accumulated price
            accumulatedPrice += price;
            
            // Check if the accumulated price exceeds k
            if (accumulatedPrice > k) {
                break;
            }
            
            // Increment num
            num++;
        }
        
        // Since the loop breaks when `num` exceeds the condition, the largest cheap number is `num - 1`
        return num - 1;
    }
};
