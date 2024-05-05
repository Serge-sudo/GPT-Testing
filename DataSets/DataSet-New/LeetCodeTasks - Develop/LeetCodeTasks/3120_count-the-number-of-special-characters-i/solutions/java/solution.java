import java.util.HashSet;

class Solution {
    public int numberOfSpecialChars(String word) {
        HashSet<Character> lowercase = new HashSet<>();
        HashSet<Character> uppercase = new HashSet<>();
        HashSet<Character> special = new HashSet<>();
        
        for (char c : word.toCharArray()) {
            if (Character.isLowerCase(c)) {
                lowercase.add(c);
                if (uppercase.contains(Character.toUpperCase(c))) {
                    special.add(Character.toLowerCase(c));
                }
            } else {
                uppercase.add(c);
                if (lowercase.contains(Character.toLowerCase(c))) {
                    special.add(Character.toLowerCase(c));
                }
            }
        }
        
        return special.size();
    }
}
