#include <stdio.h>
#include <stdbool.h>

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
    int count = 0;
    for (int i = 0; i < pointsSize; i++) {
        for (int j = 0; j < pointsSize; j++) {
            if (i != j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                // Ensure Alice (x1, y1) is at upper left and Bob (x2, y2) is at lower right
                if (x1 <= x2 && y1 >= y2) {
                    bool validPair = true;
                    for (int k = 0; k < pointsSize; k++) {
                        if (k != i && k != j) {
                            int xk = points[k][0], yk = points[k][1];
                            // Check if any other point is inside or on the boundary of the rectangle
                            if (xk >= x1 && xk <= x2 && yk <= y1 && yk >= y2) {
                                validPair = false;
                                break;
                            }
                        }
                    }
                    if (validPair) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
