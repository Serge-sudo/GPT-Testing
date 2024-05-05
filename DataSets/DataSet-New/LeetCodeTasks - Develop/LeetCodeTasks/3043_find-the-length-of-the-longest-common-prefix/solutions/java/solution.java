import java.util.Arrays;

class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        // Sort both arrays to prepare for binary search approach
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        
        int maxPrefixLength = 0;
        
        for (int num1 : arr1) {
            int left = 0, right = arr2.length - 1;
            String s1 = Integer.toString(num1);
            while (left <= right) {
                int mid = left + (right - left) / 2;
                String s2 = Integer.toString(arr2[mid]);
                int commonLength = commonPrefixLength(s1, s2);
                
                maxPrefixLength = Math.max(maxPrefixLength, commonLength);
                
                // Use the nature of sorted array to decide which direction to go
                if (s2.startsWith(s1)) {
                    // No longer prefix is possible from smaller numbers in arr2
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return maxPrefixLength;
    }
    
    private int commonPrefixLength(String s1, String s2) {
        int minLength = Math.min(s1.length(), s2.length());
        for (int i = 0; i < minLength; i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                return i;
            }
        }
        return minLength;
    }
}
