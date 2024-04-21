class Solution {
    public int romanToInt(String s) {
        int sum = 0;
        int prev = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int curr = romanValue(s.charAt(i));
            if (curr < prev)
                sum -= curr;
            else
                sum += curr;
            prev = curr;
        }
        return sum;
    }

    private int romanValue(char r) {
        switch (r) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
}
