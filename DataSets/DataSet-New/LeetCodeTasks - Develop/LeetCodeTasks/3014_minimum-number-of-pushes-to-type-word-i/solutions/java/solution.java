import java.util.HashMap;
import java.util.Map;

class Solution {
    public int minimumPushes(String word) {
        Map<Character, int[]> keypad = new HashMap<>();
        keypad.put('a', new int[]{0, 0});
        keypad.put('b', new int[]{0, 1});
        keypad.put('c', new int[]{0, 2});
        keypad.put('d', new int[]{1, 0});
        keypad.put('e', new int[]{1, 1});
        keypad.put('f', new int[]{1, 2});
        keypad.put('g', new int[]{2, 0});
        keypad.put('h', new int[]{2, 1});
        keypad.put('i', new int[]{2, 2});
        keypad.put('j', new int[]{3, 0});
        keypad.put('k', new int[]{3, 1});
        keypad.put('l', new int[]{3, 2});
        keypad.put('m', new int[]{4, 0});
        keypad.put('n', new int[]{4, 1});
        keypad.put('o', new int[]{4, 2});
        keypad.put('p', new int[]{5, 0});
        keypad.put('q', new int[]{5, 1});
        keypad.put('r', new int[]{5, 2});
        keypad.put('s', new int[]{5, 3});
        keypad.put('t', new int[]{6, 0});
        keypad.put('u', new int[]{6, 1});
        keypad.put('v', new int[]{6, 2});
        keypad.put('w', new int[]{6, 3});
        keypad.put('x', new int[]{7, 0});
        keypad.put('y', new int[]{7, 1});
        keypad.put('z', new int[]{7, 2});
        
        int result = 0;
        int[] prev = {0, 0};
        for (char c : word.toCharArray()) {
            int[] curr = keypad.get(c);
            result += Math.abs(curr[0] - prev[0]) + Math.abs(curr[1] - prev[1]) + 1;
            prev = curr;
        }
        return result;
    }
}
