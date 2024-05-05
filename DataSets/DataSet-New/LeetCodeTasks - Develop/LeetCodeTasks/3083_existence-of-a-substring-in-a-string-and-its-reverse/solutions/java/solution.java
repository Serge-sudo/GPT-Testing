class Solution {
    public boolean isSubstringPresent(String s) {
        // Create a HashSet to store the two-character substrings
        HashSet<String> seenSubstrings = new HashSet<>();
        
        // Get the reverse of the string s
        String reversed = new StringBuilder(s).reverse().toString();
        
        // Iterate over the string to find all possible two-character substrings
        for (int i = 0; i < s.length() - 1; i++) {
            // Extract the substring of length 2 from the original string
            String substr = s.substring(i, i + 2);
            // Add to the HashSet
            seenSubstrings.add(substr);
        }
        
        // Check the reverse string for any substring that has already been seen
        for (int i = 0; i < reversed.length() - 1; i++) {
            String revSubstr = reversed.substring(i, i + 2);
            // If the reversed substring exists in the HashSet, return true
            if (seenSubstrings.contains(revSubstr)) {
                return true;
            }
        }
        
        // If no matching substring is found, return false
        return false;
    }
}
