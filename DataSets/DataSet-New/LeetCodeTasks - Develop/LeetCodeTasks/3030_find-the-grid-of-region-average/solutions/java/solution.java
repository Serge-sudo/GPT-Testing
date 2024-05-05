public class Solution {
    public int[][] resultGrid(int[][] image, int threshold) {
        int m = image.length, n = image[0].length;
        int[][] result = new int[m][n];
        
        // Auxiliary function to check if a 3x3 subgrid is valid
        boolean isValidRegion(int x, int y) {
            for (int i = x; i < x + 2; i++) {
                for (int j = y; j < y + 2; j++) {
                    if (Math.abs(image[i][j] - image[i + 1][j]) > threshold) return false;
                    if (Math.abs(image[i][j] - image[i][j + 1]) > threshold) return false;
                }
            }
            for (int j = y; j < y + 2; j++) {
                if (Math.abs(image[x + 2][j] - image[x + 2][j + 1]) > threshold) return false;
            }
            for (int i = x; i < x + 2; i++) {
                if (Math.abs(image[i][y + 2] - image[i + 1][y + 2]) > threshold) return false;
            }
            return true;
        }
        
        // Calculate all valid regions
        int[][] sumRegions = new int[m][n];
        int[][] countRegions = new int[m][n];
        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                if (isValidRegion(i, j)) {
                    int sum = 0;
                    for (int x = i; x < i + 3; x++) {
                        for (int y = j; y < j + 3; y++) {
                            sum += image[x][y];
                        }
                    }
                    int avg = sum / 9; // Average of a 3x3 region, 9 elements
                    for (int x = i; x < i + 3; x++) {
                        for (int y = j; y < j + 3; y++) {
                            sumRegions[x][y] += avg;
                            countRegions[x][y]++;
                        }
                    }
                }
            }
        }
        
        // Compute result grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (countRegions[i][j] > 0) {
                    result[i][j] = sumRegions[i][j] / countRegions[i][j];
                } else {
                    result[i][j] = image[i][j];
                }
            }
        }
        
        return result;
    }
}
