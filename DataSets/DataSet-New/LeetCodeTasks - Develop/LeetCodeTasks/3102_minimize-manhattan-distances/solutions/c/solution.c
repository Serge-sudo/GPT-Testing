#include <limits.h>
#include <stdlib.h>

int manhattanDistance(int *point1, int *point2) {
    return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
}

int minimumDistance(int** points, int pointsSize, int* pointsColSize) {
    int maxDistance = INT_MIN;
    int **extremePairs = malloc(4 * sizeof(int*));
    for (int i = 0; i < 4; i++) {
        extremePairs[i] = malloc(2 * sizeof(int));
    }
    
    // Initialize extreme values
    int minX = INT_MAX, maxX = INT_MIN;
    int minY = INT_MAX, maxY = INT_MIN;
    
    // Find extremal points
    for (int i = 0; i < pointsSize; i++) {
        int x = points[i][0], y = points[i][1];
        if (x + y > maxX + maxY) { maxX = x; maxY = y; extremePairs[0][0] = x; extremePairs[0][1] = y; }
        if (x + y < minX + minY) { minX = x; minY = y; extremePairs[1][0] = x; extremePairs[1][1] = y; }
        if (x - y > maxX - maxY) { maxX = x; maxY = y; extremePairs[2][0] = x; extremePairs[2][1] = y; }
        if (x - y < minX - minY) { minX = x; minY = y; extremePairs[3][0] = x; extremePairs[3][1] = y; }
    }
    
    // Calculate max distance without removing any point
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            maxDistance = fmax(maxDistance, manhattanDistance(extremePairs[i], extremePairs[j]));
        }
    }

    // Check minimum max distance after removing each point
    int minimumMaxDistance = INT_MAX;
    for (int i = 0; i < pointsSize; i++) {
        int localMaxDistance = 0;
        for (int j = 0; j < pointsSize; j++) {
            if (i == j) continue;
            for (int k = j + 1; k < pointsSize; k++) {
                if (i == k) continue;
                localMaxDistance = fmax(localMaxDistance, manhattanDistance(points[j], points[k]));
            }
        }
        minimumMaxDistance = fmin(minimumMaxDistance, localMaxDistance);
    }
    
    for (int i = 0; i < 4; i++) {
        free(extremePairs[i]);
    }
    free(extremePairs);
    
    return minimumMaxDistance;
}
