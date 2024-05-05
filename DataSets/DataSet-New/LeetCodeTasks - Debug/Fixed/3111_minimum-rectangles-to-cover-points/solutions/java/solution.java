import java.util.Arrays;

class Solution {

    public int minRectanglesToCoverPoints(int[][] points, int w) {

        // Sort points by the x-coordinate (xi)
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));

        int countRectangles = 0;
        int i = 0;
        int n = points.length;

        while (i < n) {
            // Start a new rectangle
            countRectangles++;

            // The current rectangle starts at xi
            int startX = points[i][0];

            // The end x-coordinate of the rectangle can be at most startX + w
            int endX = startX + w;

            // Move i to the next point that is not covered by the current rectangle
            while (i < n && points[i][0] <= endX) {
                i++;
            }
        }

        return countRectangles;
    }
}
