import java.util.Arrays;

public class Solution {
    public int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {
        int[] ans = new int[wordsQuery.length];
        Arrays.fill(ans, -1);

        for (int i = 0; i < wordsQuery.length; i++) {
            String query = wordsQuery[i];
            int maxLength = -1;
            int minIndex = -1;
            int minLength = Integer.MAX_VALUE;

            for (int j = 0; j < wordsContainer.length; j++) {
                String container = wordsContainer[j];
                int commonLength = commonSuffixLength(container, query);

                if (commonLength > maxLength ||
                    (commonLength == maxLength && container.length() < minLength) ||
                    (commonLength == maxLength && container.length() == minLength && j < minIndex)) {
                    maxLength = commonLength;
                    minIndex = j;
                    minLength = container.length();
                }
            }
            ans[i] = minIndex;
        }
        return ans;
    }

    private int commonSuffixLength(String a, String b) {
        int length = 0;
        int aIndex = a.length() - 1;
        int bIndex = b.length() - 1;
        while (aIndex >= 0 && bIndex >= 0 && a.charAt(aIndex) == b.charAt(bIndex)) {
            length++;
            aIndex--;
            bIndex--;
        }
        return length;
    }
}
