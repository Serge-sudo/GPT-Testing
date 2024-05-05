import java.util.HashMap;
import java.util.Map;

class Solution {
    public int numberOfSpecialChars(String word) {
        Map<Character, Integer> lowerCases = new HashMap<>();
        Map<Character, Integer> upperCases = new HashMap<>();
        
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (Character.isLowerCase(c)) {
                lowerCases.putIfAbsent(c, i);
            } else {
                char lower = Character.toLowerCase(c);
                upperCases.putIfAbsent(lower, i);
            }
        }
        
        int specialCount = 0;
        for (char c : lowerCases.keySet()) {
            if (upperCases.containsKey(c) && lowerCases.get(c) < upperCases.get(c)) {
                specialCount++;
            }
        }
        
        return specialCount;
    }
}
