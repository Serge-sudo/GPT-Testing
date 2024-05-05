import java.util.Arrays;

public class Solution {
    public int[] countOfPairs(int n, int x, int y) {
        // Result array to hold the count of pairs for each distance
        int[] result = new int[n];
        
        // Precompute the minimum distances using Floyd-Warshall like approach
        // Initialize distance matrix
        int[][] dist = new int[n + 1][n + 1];
        for (int[] row : dist) {
            Arrays.fill(row, n + 1); // Start with a large number beyond max possible distance
        }
        for (int i = 1; i <= n; i++) {
            dist[i][i] = 0; // Distance to self is 0
            if (i < n) {
                dist[i][i + 1] = 1;
                dist[i + 1][i] = 1;
            }
        }
        
        // Special connection
        dist[x][y] = Math.min(dist[x][y], 1);
        dist[y][x] = Math.min(dist[y][x], 1);
        
        // Floyd-Warshall algorithm to find shortest paths
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        // Count pairs with exact distances
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int d = dist[i][j];
                if (d <= n) {
                    result[d]++;
                }
            }
        }
        
        // Since each pair (i, j) has a counterpart (j, i), double the count
        for (int k = 1; k < n; k++) {
            result[k] *= 2;
        }
        
        return result;
    }
}
