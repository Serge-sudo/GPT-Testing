import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        int n = s.length();
        int lenA = a.length();
        int lenB = b.length();

        // Lists to hold indices where substring a and b are found
        List<Integer> indicesA = new ArrayList<>();
        List<Integer> indicesB = new ArrayList<>();

        // Find all occurrences of a
        for (int i = 0; i <= n - lenA; i++) {
            if (s.substring(i, i + lenA).equals(a)) {
                indicesA.add(i);
            }
        }

        // Find all occurrences of b
        for (int i = 0; i <= n - lenB; i++) {
            if (s.substring(i, i + lenB).equals(b)) {
                indicesB.add(i);
            }
        }

        List<Integer> result = new ArrayList<>();
        
        // Iterate over each index where 'a' is found and check proximity to any 'b'
        for (int idxA : indicesA) {
            // Check if within k distance of any index of b
            boolean found = false;
            for (int idxB : indicesB) {
                if (Math.abs(idxB - idxA) <= k) {
                    found = true;
                    break;
                }
            }
            if (found) {
                result.add(idxA);
            }
        }

        return result;
    }
}
