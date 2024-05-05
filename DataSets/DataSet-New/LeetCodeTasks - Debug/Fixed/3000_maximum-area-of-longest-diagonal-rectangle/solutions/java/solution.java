class Solution {

    public int areaOfMaxDiagonal(int[][] dimensions) {

        double maxDiagonal = 0;
        int maxArea = 0;

        for (int[] dimension : dimensions) {
            int length = dimension[0];
            int width = dimension[1];

            double diagonal = Math.sqrt(length * length + width * width); // Fixed formula to correctly calculate the diagonal
            int area = length * width;

            if (diagonal > maxDiagonal || (diagonal == maxDiagonal && area > maxArea)) { // Fixed the condition to correctly handle both checks
                maxDiagonal = diagonal;
                maxArea = area;
            }
        }

        return maxArea;
    }
}
