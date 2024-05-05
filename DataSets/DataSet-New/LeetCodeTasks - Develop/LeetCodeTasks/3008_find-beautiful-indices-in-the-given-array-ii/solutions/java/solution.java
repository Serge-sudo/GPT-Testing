import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        List<Integer> aIndices = new ArrayList<>();
        List<Integer> bIndices = new ArrayList<>();
        List<Integer> result = new ArrayList<>();
        
        // Finding all starting indices of string 'a' in 's'
        for (int i = 0; i <= s.length() - a.length(); i++) {
            if (s.startsWith(a, i)) {
                aIndices.add(i);
            }
        }
        
        // Finding all starting indices of string 'b' in 's'
        for (int i = 0; i <= s.length() - b.length(); i++) {
            if (s.startsWith(b, i)) {
                bIndices.add(i);
            }
        }
        
        // Check each index of 'a' to find if it is beautiful
        for (int i : aIndices) {
            for (int j : bIndices) {
                if (Math.abs(i - j) <= k) {
                    result.add(i);
                    break;
                }
            }
        }
        
        return result;
    }
}
