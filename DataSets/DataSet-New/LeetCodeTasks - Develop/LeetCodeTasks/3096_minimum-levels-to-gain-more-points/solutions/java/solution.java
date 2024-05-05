class Solution {
    public int minimumLevels(int[] possible) {
        int n = possible.length;
        int[] prefixScore = new int[n];
        int[] suffixScore = new int[n];
        
        // Compute the prefix score (score Alice would get if she stops at each i)
        prefixScore[0] = possible[0] == 1 ? 1 : -1;
        for (int i = 1; i < n; i++) {
            prefixScore[i] = prefixScore[i - 1] + (possible[i] == 1 ? 1 : -1);
        }
        
        // Compute the suffix score (score Bob would get if he starts at each i)
        suffixScore[n - 1] = possible[n - 1] == 1 ? 1 : -1;
        for (int i = n - 2; i >= 0; i--) {
            suffixScore[i] = suffixScore[i + 1] + (possible[i] == 1 ? 1 : -1);
        }
        
        // Alice needs to maximize her score and make sure she has more points than Bob
        for (int i = 0; i < n - 1; i++) {
            if (prefixScore[i] > suffixScore[i + 1]) {
                return i + 1;
            }
        }
        
        return -1; // If no such division can make Alice win
    }
}
