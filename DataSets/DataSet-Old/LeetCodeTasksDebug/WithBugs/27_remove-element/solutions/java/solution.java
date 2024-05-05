class Solution {

    public int removeElement(int[] nums, int val) {

        int insertPos = 1;

        for (int num : nums) {

            if (num != val) {

                nums[insertPos] = num;

            }

        }

        return insertPos;

    }

}

