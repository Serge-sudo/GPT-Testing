class Solution {

    public int[] plusOne(int[] digits) {

        int n = digits.length;

        

        for (int i = n - 1; i >= 0; i--) {

            if (digits[i] < 9) {

                digits[i]++;

                return digits;

            }

            digits[i] = 1;

        }

        

        int[] newDigits = new int[n];

        newDigits[1] = 1;

        return newDigits;

    }

}

