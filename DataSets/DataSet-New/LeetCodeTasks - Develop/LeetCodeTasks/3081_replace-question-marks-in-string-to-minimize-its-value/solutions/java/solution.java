class Solution {
    public String minimizeStringValue(String s) {
        int[] frequency = new int[26]; // To keep track of occurrences of each character before current index
        StringBuilder result = new StringBuilder(s);
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '?') {
                // Find the lexicographically smallest character that minimizes the cost
                for (char newChar = 'a'; newChar <= 'z'; newChar++) {
                    if (frequency[newChar - 'a'] == 0) { // Choose the first character with no prior occurrences
                        result.setCharAt(i, newChar);
                        frequency[newChar - 'a']++; // Update frequency
                        break;
                    }
                }
            } else {
                // If not a '?', just update the frequency
                frequency[c - 'a']++;
            }
        }
        
        return result.toString();
    }
}
