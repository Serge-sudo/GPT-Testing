class Solution {
    public int removeDuplicates(int[] nums) {
        // Base case: if there's less than 3 items, no need to remove any
        if (nums.length < 3) return nums.length;
        
        // Index to place the next non-duplicate item
        int insertPos = 2;
        
        // Iterate over the array starting from the third element
        for (int i = 2; i < nums.length; i++) {
            // Check if the current number is not a third duplicate
            if (nums[i] != nums[insertPos - 2]) {
                nums[insertPos] = nums[i];
                insertPos++;
            }
        }
        
        // insertPos will be the new length of the array without extra duplicates
        return insertPos;
    }
}
