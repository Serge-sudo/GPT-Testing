import java.util.ArrayList;

public class Solution {
    public String lastNonEmptyString(String s) {
        while (true) {
            StringBuilder next = new StringBuilder();
            ArrayList<Integer> visited = new ArrayList<>(26);
            for (int i = 0; i < 26; i++) visited.add(0);
            for (char ch : s.toCharArray()) {
                int idx = ch - 'a';
                if (visited.get(idx) == 0) {
                    visited.set(idx, 1);
                } else {
                    next.append(ch);
                }
            }
            if (next.length() == 0) {
                return s;
            }
            s = next.toString();
        }
    }
}
