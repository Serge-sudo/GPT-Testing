#include <math.h>

int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize) {
    double maxDiagonal = 0.0;
    int maxArea = 0;

    for (int i = 0; i < dimensionsSize; i++) {
        int length = dimensions[i][0];
        int width = dimensions[i][1];
        double diagonal = sqrt(length * length + width * width);
        int area = length * width;

        if (diagonal > maxDiagonal) {
            maxDiagonal = diagonal;
            maxArea = area;
        } else if (diagonal == maxDiagonal && area > maxArea) {
            maxArea = area;
        }
    }

    return maxArea;
}
