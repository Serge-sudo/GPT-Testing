public class Solution {

    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {

        int n = bottomLeft.length;

        long maxSquareArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Calculate intersection bounds
                int intersectLeft = Math.max(bottomLeft[i][0], bottomLeft[j][0]);
                int intersectBottom = Math.max(bottomLeft[i][1], bottomLeft[j][1]);
                int intersectRight = Math.min(topRight[i][0], topRight[j][0]);
                int intersectTop = Math.min(topRight[i][1], topRight[j][1]);

                if (intersectLeft < intersectRight && intersectBottom < intersectTop) {
                    // Calculate the possible side length of the largest square within the intersection
                    int width = intersectRight - intersectLeft;
                    int height = intersectTop - intersectBottom;
                    int sideLength = Math.min(width, height);

                    maxSquareArea = Math.max(maxSquareArea, (long) sideLength * sideLength);
                }
            }
        }

        return maxSquareArea;
    }
}
