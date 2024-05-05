import java.util.ArrayList;
import java.util.List;
import java.util.TreeSet;

class Solution {
    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        List<Integer> result = new ArrayList<>();
        TreeSet<Integer> bIndices = new TreeSet<>();

        int aLen = a.length();
        int bLen = b.length();
        int n = s.length();

        // Collect all indices where substring b is found
        for (int j = 0; j <= n - bLen; j++) {
            if (s.substring(j, j + bLen).equals(b)) {
                bIndices.add(j);
            }
        }

        // Check for each index where substring a is found if it is beautiful
        for (int i = 0; i <= n - aLen; i++) {
            if (s.substring(i, i + aLen).equals(a)) {
                // Check if there exists an index j such that |j - i| <= k
                Integer floor = bIndices.floor(i + k);
                Integer ceiling = bIndices.ceiling(i - k);
                if ((floor != null && floor >= i) || (ceiling != null && ceiling <= i + k)) {
                    result.add(i);
                }
            }
        }

        return result;
    }
}
