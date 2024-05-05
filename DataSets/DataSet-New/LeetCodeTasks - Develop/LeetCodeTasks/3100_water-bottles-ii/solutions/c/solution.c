#include <stdio.h>

int maxBottlesDrunk(int numBottles, int numExchange) {
    int totalDrank = 0;
    int emptyBottles = 0;
    int currentExchange = numExchange;

    while (numBottles > 0) {
        // Drink all current bottles
        totalDrank += numBottles;
        emptyBottles += numBottles;
        numBottles = 0;

        // Exchange empty bottles for new full ones
        if (emptyBottles >= currentExchange) {
            numBottles += emptyBottles / currentExchange;
            emptyBottles %= currentExchange;
            currentExchange++;
        }
    }

    return totalDrank;
}
