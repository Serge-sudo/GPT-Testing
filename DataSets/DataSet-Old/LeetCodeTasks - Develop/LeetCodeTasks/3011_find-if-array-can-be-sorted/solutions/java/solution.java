import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public boolean canSortArray(int[] nums) {
        // Create an array of the same size to store numbers with their bit counts
        Integer[] numBits = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            numBits[i] = nums[i];
        }
        
        // Custom comparator to sort numbers based on bit counts, and then by value
        Arrays.sort(numBits, new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                int count1 = Integer.bitCount(o1);
                int count2 = Integer.bitCount(o2);
                if (count1 == count2) {
                    return Integer.compare(o1, o2);
                }
                return Integer.compare(count1, count2);
            }
        });
        
        // Check if we can form a sorted sequence of original numbers
        // just by comparing bit counts
        for (int i = 0; i < nums.length - 1; i++) {
            if (Integer.bitCount(numBits[i]) > Integer.bitCount(numBits[i + 1])) {
                return false;
            }
        }
        
        return true;
    }
}
