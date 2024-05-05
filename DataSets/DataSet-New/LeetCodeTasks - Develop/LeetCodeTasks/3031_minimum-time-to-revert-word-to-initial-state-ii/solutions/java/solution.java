class Solution {
    public int minimumTimeToInitialState(String word, int k) {
        int n = word.length();
        int g = gcd(n, k);
        return n / g;
    }
    
    private int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
}
