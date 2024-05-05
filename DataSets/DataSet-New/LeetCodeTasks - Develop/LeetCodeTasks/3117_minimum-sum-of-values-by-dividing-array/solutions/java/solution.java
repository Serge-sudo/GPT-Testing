import java.util.Arrays;

public class Solution {
    public int minimumValueSum(int[] nums, int[] andValues) {
        int n = nums.length;
        int m = andValues.length;
        int[][] dp = new int[m + 1][n + 1];
        for (int[] row : dp) Arrays.fill(row, Integer.MAX_VALUE / 2);
        dp[0][0] = 0;
        
        for (int i = 1; i <= m; i++) {
            int requiredAnd = andValues[i - 1];
            for (int j = i - 1; j < n; j++) {
                int andAccum = nums[j];
                for (int k = j; k >= i - 1; k--) {
                    if (k < j) {
                        andAccum &= nums[k];
                    }
                    if (andAccum == requiredAnd) {
                        dp[i][j + 1] = Math.min(dp[i][j + 1], dp[i - 1][k] + nums[j]);
                    }
                }
            }
        }
        
        int answer = dp[m][n];
        return answer < Integer.MAX_VALUE / 2 ? answer : -1;
    }
}
