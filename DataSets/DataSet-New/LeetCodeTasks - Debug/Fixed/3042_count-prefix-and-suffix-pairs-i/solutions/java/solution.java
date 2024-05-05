class Solution {

    public int countPrefixSuffixPairs(String[] words) {

        int count = 0;

        for (int i = 0; i < words.length; i++) {
            for (int j = i + 1; j < words.length; j++) {  // Corrected from j <= words.length to j < words.length
                if (isPrefixAndSuffix(words[i], words[j])) {  // Corrected the order of arguments
                    count++;
                }
            }
        }

        return count;

    }

    private boolean isPrefixAndSuffix(String str1, String str2) {
        return str2.startsWith(str1) && str2.endsWith(str1);  // Corrected '&' to '&&'
    }
}
