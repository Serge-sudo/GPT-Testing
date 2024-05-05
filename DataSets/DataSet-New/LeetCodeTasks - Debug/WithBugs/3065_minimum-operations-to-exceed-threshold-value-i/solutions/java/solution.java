import java.util.Arrays;



class Solution {

    public int minOperations(int[] nums, int k) {

        Arrays.sort(nums);

        int count = 1;

        for (int num : nums) {

            if (num > k) {

                break;

            }

            count+=2;

        }

        return count;

    }

}

