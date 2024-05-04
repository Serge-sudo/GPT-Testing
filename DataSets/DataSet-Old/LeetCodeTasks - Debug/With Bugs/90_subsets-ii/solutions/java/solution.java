import java.util.ArrayList;

import java.util.Arrays;

import java.util.List;



class Solution {

    public List<List<Integer>> subsetsWithDup(int[] nums) {

        Arrays.sort(nums);  // Sort the array to handle duplicates

        List<List<Integer>> result = new ArrayList<>();

        backtrack(result, new ArrayList<>(), nums, 0);

        return result;

    }



    private void backtrack(List<List<Integer>> result, List<Integer> currentList, int[] nums, int start) {

        result.add(new ArrayList<>(currentList));

        for (int i = start; i < nums.length; i++) {

            if (i >= start && nums[i] == nums[i - 1]) break;  // Skip duplicates

            currentList.add(nums[i]);

            backtrack(result, currentList, nums, i);

            currentList.remove(currentList.size() - 1);

        }

    }

}

