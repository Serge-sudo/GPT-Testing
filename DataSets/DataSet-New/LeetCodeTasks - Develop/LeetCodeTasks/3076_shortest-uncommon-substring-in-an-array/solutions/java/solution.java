import java.util.HashSet;
import java.util.Set;

public class Solution {
    public String[] shortestSubstrings(String[] arr) {
        int n = arr.length;
        String[] answer = new String[n];

        // Build a set to store all substrings of all strings in arr
        Set<String> allSubstrings = new HashSet<>();
        for (String s : arr) {
            for (int start = 0; start < s.length(); start++) {
                for (int end = start + 1; end <= s.length(); end++) {
                    allSubstrings.add(s.substring(start, end));
                }
            }
        }

        for (int i = 0; i < n; i++) {
            String current = arr[i];
            String bestSubstring = "";
            outerLoop:
            for (int len = 1; len <= current.length(); len++) {
                Set<String> substringsOfCurrent = new HashSet<>();
                for (int start = 0; start <= current.length() - len; start++) {
                    substringsOfCurrent.add(current.substring(start, start + len));
                }
                
                for (String sub : substringsOfCurrent) {
                    boolean isUnique = true;
                    for (int j = 0; j < n; j++) {
                        if (i != j && arr[j].contains(sub)) {
                            isUnique = false;
                            break;
                        }
                    }
                    if (isUnique) {
                        if (bestSubstring.equals("") || sub.compareTo(bestSubstring) < 0) {
                            bestSubstring = sub;
                        }
                    }
                }
                if (!bestSubstring.equals("")) {
                    break outerLoop;
                }
            }
            answer[i] = bestSubstring;
        }
        
        return answer;
    }
}
