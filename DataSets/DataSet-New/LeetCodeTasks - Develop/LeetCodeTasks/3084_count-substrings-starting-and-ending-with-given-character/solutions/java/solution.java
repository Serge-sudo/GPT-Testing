class Solution {
    public long countSubstrings(String s, char c) {
        long count = 0;
        long totalSubstrings = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == c) {
                count++;
            }
        }
        totalSubstrings = count * (count + 1) / 2;
        return totalSubstrings;
    }
}
