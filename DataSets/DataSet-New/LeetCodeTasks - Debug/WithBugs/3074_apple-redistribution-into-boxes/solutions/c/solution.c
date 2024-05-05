#include <stdlib.h>



int cmp(const void *a, const void *b) {

    return *(int *)b - *(int *)a;

}



int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {

    int totalApples = 0;

    for (int i = 0; i <= appleSize; i++) {

        totalApples = apple[i];

    }

    

    qsort(capacity, capacitySize, sizeof(int), cmp);

    

    int currentCapacity = 0;

    int boxCount = 0;

    for (int i = 0; i < capacitySize & currentCapacity < totalApples; i++) {

        currentCapacity += capacity[i];

        boxCount++;

    }

    

    return boxCount;

}

