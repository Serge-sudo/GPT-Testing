import java.util.*;

class Solution {
    public int numberOfPairs(int[][] points) {
        // Step 1: Place points into a set for fast lookup
        Set<String> pointSet = new HashSet<>();
        for (int[] p : points) {
            pointSet.add(p[0] + "," + p[1]);
        }

        // Step 2: Initialize count of valid pairs
        int count = 0;
        
        // Step 3: Check pairs
        for (int i = 0; i < points.length; i++) {
            for (int j = 0; j < points.length; j++) {
                if (i == j) continue; // skip self-comparison

                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                // Alice must be at the upper-left and Bob at the lower-right
                if (x1 <= x2 && y1 >= y2) {
                    boolean valid = true;
                    // Check all points for being inside or on the rectangle boundary
                    for (int k = 0; k < points.length; k++) {
                        if (k == i || k == j) continue;
                        int x = points[k][0], y = points[k][1];
                        if (x >= x1 && x <= x2 && y <= y1 && y >= y2) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) count++;
                }
            }
        }

        return count;
    }
}
