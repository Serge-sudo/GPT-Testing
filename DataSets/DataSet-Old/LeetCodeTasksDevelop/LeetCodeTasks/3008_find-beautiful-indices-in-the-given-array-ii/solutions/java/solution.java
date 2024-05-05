import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        int n = s.length();
        int lenA = a.length();
        int lenB = b.length();
        
        // Finding all the starting indices where string a appears in s
        List<Integer> aIndices = new ArrayList<>();
        for (int i = 0; i <= n - lenA; i++) {
            if (s.substring(i, i + lenA).equals(a)) {
                aIndices.add(i);
            }
        }
        
        // Finding all the starting indices where string b appears in s
        List<Integer> bIndices = new ArrayList<>();
        for (int i = 0; i <= n - lenB; i++) {
            if (s.substring(i, i + lenB).equals(b)) {
                bIndices.add(i);
            }
        }
        
        // Collecting beautiful indices
        List<Integer> result = new ArrayList<>();
        for (int indexA : aIndices) {
            // Check if there exists any index j for b such that |j - indexA| <= k
            boolean found = false;
            for (int indexB : bIndices) {
                if (Math.abs(indexB - indexA) <= k) {
                    found = true;
                    break;
                }
            }
            if (found) {
                result.add(indexA);
            }
        }
        
        return result;
    }
}
