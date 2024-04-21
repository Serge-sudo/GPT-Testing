class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) return "0";
        int len1 = num1.length(), len2 = num2.length();
        int[] position = new int[len1 + len2];

        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + position[p2];

                position[p1] += sum / 10;
                position[p2] = sum % 10;
            }
        }

        StringBuilder result = new StringBuilder();
        for (int p : position) if (!(result.length() == 0 && p == 0)) result.append(p);
        return result.toString();
    }
}
