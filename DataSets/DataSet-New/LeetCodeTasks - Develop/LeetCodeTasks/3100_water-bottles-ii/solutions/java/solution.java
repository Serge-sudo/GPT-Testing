#include <iostream>

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrunk = 0;
        int emptyBottles = 0;
        
        while (numBottles > 0) {
            // Drink all full bottles
            totalDrunk += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;

            // Exchange empty bottles for new full bottles if possible
            if (emptyBottles >= numExchange) {
                numBottles = emptyBottles / numExchange;
                emptyBottles %= numExchange;
                numExchange++;
            }
        }
        return totalDrunk;
    }
};
