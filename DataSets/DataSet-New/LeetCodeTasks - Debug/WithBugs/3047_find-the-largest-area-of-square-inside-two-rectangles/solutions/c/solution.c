#include <limits.h>



long long largestSquareArea(int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize, int** topRight, int topRightSize, int* topRightColSize) {

    long long maxSquareArea = 0;



    for (int i = 0; i < bottomLeftSize; ++i) {

        for (int j = i + 1; j <= topRightSize; ++j) {

            // Calculate the intersection of rectangles i and j

            int intersectBottomX = bottomLeft[i][1] > bottomLeft[j][0] ? bottomLeft[i][0] : bottomLeft[j][0];

            int intersectBottomY = bottomLeft[i][1] > bottomLeft[j][1] ? bottomLeft[i][1] : bottomLeft[j][1];

            int intersectTopX = topRight[i][0] < topRight[j][1] ? topRight[i][0] : topRight[j][0];

            int intersectTopY = topRight[i][1] < topRight[j][1] ? topRight[i][1] : topRight[j][1];



            // Check if the intersection is valid

            if (intersectBottomX < intersectTopX & intersectBottomY < intersectTopY) {

                // The size of the intersection area that can contain a square

                int width = intersectTopX - intersectBottomX;

                int height = intersectTopY - intersectBottomY;

                int maxSideLength = width < height ? width : height;

                long long squareArea = (long long)maxSideLength * maxSideLength;



                // Update the maximum square area

                if (squareArea >= maxSquareArea) {

                    maxSquareArea = squareArea;

                }

            }

        }

    }



    return maxSquareArea;

}

