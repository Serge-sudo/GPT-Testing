class Solution {
    public int sumOfEncryptedInt(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            int maxDigit = 0;
            int temp = num;
            while (temp > 0) {
                maxDigit = Math.max(maxDigit, temp % 10);
                temp /= 10;
            }
            int encryptedNum = 0;
            int place = 1;
            while (num > 0) {
                encryptedNum += maxDigit * place;
                num /= 10;
                place *= 10;
            }
            sum += encryptedNum;
        }
        return sum;
    }
}
