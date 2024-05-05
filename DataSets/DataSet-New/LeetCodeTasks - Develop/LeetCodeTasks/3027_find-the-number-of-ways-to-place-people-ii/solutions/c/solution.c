#include <stdlib.h>

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
    int result = 0;
    
    for (int i = 0; i < pointsSize; i++) {
        for (int j = 0; j < pointsSize; j++) {
            if (i != j) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                // Check Alice (x1, y1) is upper left and Bob (x2, y2) is lower right
                if (x1 < x2 && y1 > y2) {
                    int valid = 1;
                    
                    // Verify no other point (x3, y3) is within the rectangle or on the boundary
                    for (int k = 0; k < pointsSize; k++) {
                        if (k != i && k != j) {
                            int x3 = points[k][0];
                            int y3 = points[k][1];
                            
                            if (x3 >= x1 && x3 <= x2 && y3 <= y1 && y3 >= y2) {
                                valid = 0;
                                break;
                            }
                        }
                    }
                    
                    if (valid) {
                        result++;
                    }
                }
            }
        }
    }
    
    return result;
}
