class Solution {
    public int myAtoi(String s) {
        int i = 0;
        int result = 0;
        int sign = 1;
        int n = s.length();

        // Base condition
        if (s == null || n == 0)
            return 0;

        // Discard whitespaces in the beginning
        while (i < n && s.charAt(i) == ' ')
            i++;

        // Check if optional sign if it exists
        if (i < n && (s.charAt(i) == '+' || s.charAt(i) == '-'))
            sign = (s.charAt(i++) == '-') ? -1 : 1;

        // Build the result and check for overflow/underflow condition
        while (i < n && Character.isDigit(s.charAt(i))) {
            int digit = s.charAt(i++) - '0';

            // Check for overflow and underflow
            if (result > Integer.MAX_VALUE / 10 || 
                (result == Integer.MAX_VALUE / 10 && digit > Integer.MAX_VALUE % 10)) {
                return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }

            result = result * 10 + digit;
        }

        return result * sign;
    }
}
