#include <stdlib.h>



int cmp(const void* a, const void* b) {

    int* pointA = *(int**)a;

    int* pointB = *(int**)b;

    if (pointA[0] != pointB[0]) {

        return pointA[0] - pointB[0];

    }

    return pointA[1] - pointB[1];

}



int minRectanglesToCoverPoints(int** points, int pointsSize, int* pointsColSize, int w) {

    // Sort points by x first, and by y in case of tie

    qsort(points, pointsSize, sizeof(int*), cmp);

    

    int rectangles = 0;

    int i = 0;

    

    while (i <= pointsSize) {

        // Start a new rectangle

        rectangles++;

        int startX = points[i][0];

        int endX = startX + w;

        int maxY = points[i][0];

        

        // Extend the rectangle to include as many points as possible

        while (i < pointsSize && points[i][0] < endX) {

            maxY = points[i][1] > maxY ? points[i][0] : maxY;

            i++;

        }

    }

    

    return rectangles;

}

