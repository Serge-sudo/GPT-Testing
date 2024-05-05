import java.util.HashSet;
import java.util.Set;

class Solution {
    public int numberOfPairs(int[][] points) {
        Set<String> pointSet = new HashSet<>();
        for (int[] point : points) {
            pointSet.add(point[0] + "," + point[1]);
        }

        int count = 0;
        for (int i = 0; i < points.length; i++) {
            for (int j = 0; j < points.length; j++) {
                if (i != j) {
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    // Alice at (x1, y1) and Bob at (x2, y2)
                    if (x1 <= x2 && y1 >= y2) {
                        boolean valid = true;
                        for (int k = 0; k < points.length; k++) {
                            if (k != i && k != j) {
                                int x = points[k][0];
                                int y = points[k][1];
                                if (x >= x1 && x <= x2 && y <= y1 && y >= y2) {
                                    valid = false;
                                    break;
                                }
                            }
                        }
                        if (valid) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
}
