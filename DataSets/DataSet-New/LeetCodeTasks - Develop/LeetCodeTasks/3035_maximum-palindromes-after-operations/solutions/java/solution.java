import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxPalindromesAfterOperations(String[] words) {
        Map<Character, Integer> frequency = new HashMap<>();
        
        // Count all character frequencies across all words
        for (String word : words) {
            for (char c : word.toCharArray()) {
                frequency.put(c, frequency.getOrDefault(c, 0) + 1);
            }
        }
        
        int maxPalindromes = 0;
        
        // Determine maximum number of palindromes that can be formed
        int oddCount = 0;
        for (int count : frequency.values()) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }
        
        // Each palindrome needs at most one odd character count
        // The number of palindromes that can be formed is the total number of strings minus 
        // the surplus of odd character counts (more odd counts than words would mean we can't form that many palindromes)
        maxPalindromes = words.length - Math.max(0, oddCount - words.length);
        
        return maxPalindromes;
    }
}
