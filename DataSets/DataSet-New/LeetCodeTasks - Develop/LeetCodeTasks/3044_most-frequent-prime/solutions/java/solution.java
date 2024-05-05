import java.util.HashMap;
import java.util.HashSet;

public class Solution {
    public int mostFrequentPrime(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;

        // Directions encoded as {deltaX, deltaY}
        int[][] directions = {
            {0, 1},   // East
            {1, 1},   // South-East
            {1, 0},   // South
            {1, -1},  // South-West
            {0, -1},  // West
            {-1, -1}, // North-West
            {-1, 0},  // North
            {-1, 1}   // North-East
        };

        // Map to count frequencies of prime numbers greater than 10
        HashMap<Integer, Integer> primeCount = new HashMap<>();

        // Helper to check if a number is prime
        HashSet<Integer> cachePrime = new HashSet<>();
        cachePrime.add(2);
        cachePrime.add(3);
        cachePrime.add(5);
        cachePrime.add(7);
        cachePrime.add(11);
        cachePrime.add(13);
        cachePrime.add(17);
        cachePrime.add(19);
        cachePrime.add(23);
        cachePrime.add(29);
        cachePrime.add(31);
        cachePrime.add(37);
        cachePrime.add(41);
        cachePrime.add(43);
        cachePrime.add(47);
        cachePrime.add(53);
        cachePrime.add(59);
        cachePrime.add(61);
        cachePrime.add(67);
        cachePrime.add(71);
        cachePrime.add(73);
        cachePrime.add(79);
        cachePrime.add(83);
        cachePrime.add(89);
        cachePrime.add(97);

        // Check for each starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Check for each direction
                for (int[] dir : directions) {
                    int dx = dir[0];
                    int dy = dir[1];
                    int x = i;
                    int y = j;
                    StringBuilder numBuilder = new StringBuilder();
                    while (x >= 0 && x < m && y >= 0 && y < n) {
                        numBuilder.append(mat[x][y]);
                        int num = Integer.parseInt(numBuilder.toString());
                        if (num > 10 && isPrime(num, cachePrime)) {
                            primeCount.put(num, primeCount.getOrDefault(num, 0) + 1);
                        }
                        x += dx;
                        y += dy;
                    }
                }
            }
        }

        // Determine the most frequent and largest prime greater than 10
        int mostFrequent = -1;
        int maxCount = 0;
        for (int num : primeCount.keySet()) {
            int count = primeCount.get(num);
            if (count > maxCount || (count == maxCount && num > mostFrequent)) {
                maxCount = count;
                mostFrequent = num;
            }
        }

        return mostFrequent;
    }

    private boolean isPrime(int num, HashSet<Integer> cachePrime) {
        if (num <= 1) return false;
        if (cachePrime.contains(num)) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        cachePrime.add(num);
        return true;
    }
}
