import java.util.Arrays;

class Solution {
    public int minimumPushes(String word) {
        char[] chars = word.toCharArray();
        Arrays.sort(chars);
        int pushes = 0;
        
        for (int i = 0; i < chars.length; i++) {
            // Distribute letters across keys, starting with 1 push per key up to 3 pushes,
            // and then repeating with next set of 8 keys for additional pushes
            int pushesForThisChar = (i % 8) + 1; // The position within a group of 8 plus one (for 1-based counting)
            if (pushesForThisChar > 3) {
                pushesForThisChar = 3; // Maximum pushes on any key should be 3
            }
            pushes += pushesForThisChar;
        }
        
        return pushes;
    }
}
