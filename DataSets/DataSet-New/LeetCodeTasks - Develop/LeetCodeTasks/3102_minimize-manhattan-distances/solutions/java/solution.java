class Solution {
    public int minMaxDist(int[][] points) {
        int n = points.length;
        int[] minX = new int[n];
        int[] maxX = new int[n];
        int[] minY = new int[n];
        int[] maxY = new int[n];

        // Initializing extreme values
        minX[0] = minY[0] = Integer.MAX_VALUE;
        maxX[0] = maxY[0] = Integer.MIN_VALUE;

        // Forward pass to compute min/max bounds excluding current from the start
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                minX[i] = Math.min(minX[i - 1], points[i - 1][0] + points[i - 1][1]);
                maxX[i] = Math.max(maxX[i - 1], points[i - 1][0] + points[i - 1][1]);
                minY[i] = Math.min(minY[i - 1], points[i - 1][0] - points[i - 1][1]);
                maxY[i] = Math.max(maxY[i - 1], points[i - 1][0] - points[i - 1][1]);
            }
        }

        // Variables for backward computation of bounds
        int minXF = Integer.MAX_VALUE;
        int maxXF = Integer.MIN_VALUE;
        int minYF = Integer.MAX_VALUE;
        int maxYF = Integer.MIN_VALUE;

        int result = Integer.MAX_VALUE;

        // Backward pass to compute min/max bounds excluding current from the end
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                minXF = Math.min(minXF, points[i + 1][0] + points[i + 1][1]);
                maxXF = Math.max(maxXF, points[i + 1][0] + points[i + 1][1]);
                minYF = Math.min(minYF, points[i + 1][0] - points[i + 1][1]);
                maxYF = Math.max(maxYF, points[i + 1][0] - points[i + 1][1]);
            }

            // Calculate the maximum Manhattan distance possible excluding the current point i
            int maxDist = 0;
            if (i > 0) {
                maxDist = Math.max(maxDist, Math.max(
                    Math.abs(maxX[i - 1] - minXF),
                    Math.abs(minX[i - 1] - maxXF)));
                maxDist = Math.max(maxDist, Math.max(
                    Math.abs(maxY[i - 1] - minYF),
                    Math.abs(minY[i - 1] - maxYF)));
            }
            if (i < n - 1) {
                maxDist = Math.max(maxDist, Math.max(
                    Math.abs(maxXF - minX[i]),
                    Math.abs(minXF - maxX[i])));
                maxDist = Math.max(maxDist, Math.max(
                    Math.abs(maxYF - minY[i]),
                    Math.abs(minYF - maxY[i])));
            }

            // Update the result with the minimum of the maximum distances found
            result = Math.min(result, maxDist);
        }

        return result;
    }
}
