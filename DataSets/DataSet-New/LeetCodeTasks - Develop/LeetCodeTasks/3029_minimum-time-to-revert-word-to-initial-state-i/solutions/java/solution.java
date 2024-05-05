class Solution {
    public int minimumTimeToInitialState(String word, int k) {
        int n = word.length();
        if (k == n) return 1; // If k equals the length of the word, one operation restores it

        String current = word;
        for (int time = 1; time <= n; time++) {
            String prefix = current.substring(0, k);
            String suffix = current.substring(k);
            current = suffix + prefix;
            if (current.equals(word)) {
                return time;
            }
        }
        return n; // Fallback, theoretical maximum cycles back after n operations
    }
}
