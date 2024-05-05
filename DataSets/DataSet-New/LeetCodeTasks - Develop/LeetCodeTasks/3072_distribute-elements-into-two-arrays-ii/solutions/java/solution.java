import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] resultArray(int[] nums) {
        List<Integer> arr1 = new ArrayList<>();
        List<Integer> arr2 = new ArrayList<>();
        
        // First element always goes to arr1
        arr1.add(nums[0]);
        // Second element always goes to arr2
        if (nums.length > 1) {
            arr2.add(nums[1]);
        }
        
        // Function to count the elements greater than 'val' in a list
        int greaterCount(List<Integer> arr, int val) {
            int count = 0;
            for (int num : arr) {
                if (num > val) count++;
            }
            return count;
        }
        
        // Starting from the third element in nums
        for (int i = 2; i < nums.length; i++) {
            int count1 = greaterCount(arr1, nums[i]);
            int count2 = greaterCount(arr2, nums[i]);
            
            if (count1 > count2) {
                arr1.add(nums[i]);
            } else if (count1 < count2) {
                arr2.add(nums[i]);
            } else {
                if (arr1.size() <= arr2.size()) {
                    arr1.add(nums[i]);
                } else {
                    arr2.add(nums[i]);
                }
            }
        }
        
        // Concatenate arr1 and arr2 into result
        int[] result = new int[nums.length];
        int index = 0;
        for (int num : arr1) {
            result[index++] = num;
        }
        for (int num : arr2) {
            result[index++] = num;
        }
        
        return result;
    }
}
