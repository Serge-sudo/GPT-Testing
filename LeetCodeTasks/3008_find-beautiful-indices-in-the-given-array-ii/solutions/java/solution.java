import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        List<Integer> indicesA = new ArrayList<>();
        List<Integer> indicesB = new ArrayList<>();
        List<Integer> beautifulIndices = new ArrayList<>();
        
        int lengthA = a.length();
        int lengthB = b.length();
        
        // Find all starting indices of substring a in s
        for (int i = 0; i <= s.length() - lengthA; i++) {
            if (s.startsWith(a, i)) {
                indicesA.add(i);
            }
        }
        
        // Find all starting indices of substring b in s
        for (int i = 0; i <= s.length() - lengthB; i++) {
            if (s.startsWith(b, i)) {
                indicesB.add(i);
            }
        }
        
        // For each index in indicesA, check if there is any index in indicesB such that |i - j| <= k
        for (int indexA : indicesA) {
            for (int indexB : indicesB) {
                if (Math.abs(indexA - indexB) <= k) {
                    beautifulIndices.add(indexA);
                    break; // Break as soon as we find a valid indexB for current indexA
                }
            }
        }
        
        return beautifulIndices;
    }
}
