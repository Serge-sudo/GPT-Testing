import java.util.HashMap;
import java.util.Map;

class Solution {
    public int minimumPushes(String word) {
        Map<Character, Integer> keyMap = new HashMap<>();
        keyMap.put('a', 2);
        keyMap.put('b', 3);
        keyMap.put('c', 4);
        keyMap.put('d', 5);
        keyMap.put('e', 6);
        keyMap.put('f', 7);
        keyMap.put('g', 8);
        keyMap.put('h', 9);
        keyMap.put('i', 9);

        int totalPushes = 0;
        char prev = ' ';
        for (char c : word.toCharArray()) {
            if (keyMap.containsKey(c)) {
                int currentKey = keyMap.get(c);
                if (prev == c) {
                    totalPushes += 2;
                } else {
                    totalPushes += 1;
                }
                prev = c;
            }
        }
        return totalPushes;
    }
}
