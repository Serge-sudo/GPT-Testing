class Solution {
    public int sumOfTheDigitsOfHarshadNumber(int x) {
        int sumOfDigits = 0;
        int original = x;
        while (x > 0) {
            sumOfDigits += x % 10;
            x /= 10;
        }
        if (original % sumOfDigits == 0) {
            return sumOfDigits;
        } else {
            return -1;
        }
    }
}
