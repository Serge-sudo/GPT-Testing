class Solution {

    public int lengthOfLastWord(String s) {
        int length = 0;
        boolean charFound = false;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) != ' ') {
                length++;
                charFound = true;
            } else if (charFound) {
                break;
            }
        }

        return length;
    }

}
