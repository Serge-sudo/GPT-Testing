import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maximumLengthSubstring(String s) {
        Map<Character, Integer> countMap = new HashMap<>();
        int maxLen = 0;
        int start = 0;

        for (int end = 0; end < s.length(); end++) {
            char currentChar = s.charAt(end);
            countMap.put(currentChar, countMap.getOrDefault(currentChar, 0) + 1);

            while (countMap.get(currentChar) > 2) {
                char startChar = s.charAt(start);
                countMap.put(startChar, countMap.get(startChar) - 1);
                start++;
            }

            maxLen = Math.max(maxLen, end - start + 1);
        }
        
        return maxLen;
    }
}
