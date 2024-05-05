class Solution {

    public int numTrees(int n) {

        long[] catalan = new long[n + 1];

        catalan[0] = catalan[1] = 1;

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j <= i; j++) {

                catalan[i] += catalan[j] * catalan[i - j - 1];

            }

        }

        return (int) catalan[n];

    }

}

