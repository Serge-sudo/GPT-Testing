class Solution {
    public int countKeyChanges(String s) {
        int changes = 0;
        char prev = '\0'; // Initialize prev to a non-letter character
        for (char c : s.toCharArray()) {
            if (Character.isLetter(c) && Character.toLowerCase(c) != prev) {
                changes++;
                prev = Character.toLowerCase(c);
            }
        }
        return changes;
    }
}
