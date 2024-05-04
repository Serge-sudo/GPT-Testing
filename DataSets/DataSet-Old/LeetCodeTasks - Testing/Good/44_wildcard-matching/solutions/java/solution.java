class Solution {
    public boolean isMatch(String s, String p) {
        int sLen = s.length(), pLen = p.length();
        int sIdx = 0, pIdx = 0, starIdx = -1, sTmpIdx = -1;

        while (sIdx < sLen) {
            if (pIdx < pLen && (p.charAt(pIdx) == '?' || p.charAt(pIdx) == s.charAt(sIdx))) {
                // Move both pointers when the characters match or '?'
                sIdx++;
                pIdx++;
            } else if (pIdx < pLen && p.charAt(pIdx) == '*') {
                // If a '*' is found, mark the position and the sIdx
                starIdx = pIdx;
                sTmpIdx = sIdx;
                pIdx++;
            } else if (starIdx == -1) {
                // If there are no '*' left to cover the mismatch
                return false;
            } else {
                // If mismatch happens and a '*' was previously encountered
                // backtrack to the last '*' and match this part
                pIdx = starIdx + 1;
                sIdx = sTmpIdx + 1;
                sTmpIdx = sIdx;
            }
        }

        // Check for remaining characters in pattern
        for (int i = pIdx; i < pLen; i++) {
            if (p.charAt(i) != '*') {
                return false;
            }
        }

        return true;
    }
}
