class Solution {
    public String countAndSay(int n) {
        if (n == 1) return "1";
        String previous = countAndSay(n - 1);
        StringBuilder result = new StringBuilder();
        
        int count = 0;
        char currentChar = previous.charAt(0);
        
        for (int i = 0; i < previous.length(); i++) {
            if (previous.charAt(i) == currentChar) {
                count++;
            } else {
                result.append(count).append(currentChar);
                currentChar = previous.charAt(i);
                count = 1;
            }
        }
        
        result.append(count).append(currentChar);
        return result.toString();
    }
}
