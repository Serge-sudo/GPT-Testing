import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> validIPs = new ArrayList<>();
        int n = s.length();
        
        for (int i = 1; i <= 3 && i < n; i++) {
            for (int j = i + 1; j <= i + 3 && j < n; j++) {
                for (int k = j + 1; k <= j + 3 && k < n; k++) {
                    // Divide s into four parts
                    String part1 = s.substring(0, i);
                    String part2 = s.substring(i, j);
                    String part3 = s.substring(j, k);
                    String part4 = s.substring(k, n);
                    
                    // Check each part is valid or not
                    if (isValid(part1) && isValid(part2) && isValid(part3) && isValid(part4)) {
                        validIPs.add(part1 + "." + part2 + "." + part3 + "." + part4);
                    }
                }
            }
        }
        
        return validIPs;
    }
    
    private boolean isValid(String part) {
        if (part.length() > 3 || part.length() == 0 || (part.charAt(0) == '0' && part.length() > 1) || Integer.parseInt(part) > 255)
            return false;
        return true;
    }
}
