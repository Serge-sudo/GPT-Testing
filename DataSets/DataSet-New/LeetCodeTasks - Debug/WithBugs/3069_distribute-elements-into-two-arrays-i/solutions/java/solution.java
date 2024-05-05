class Solution {

    public int[] resultArray(int[] nums) {

        // Initial lists to collect the split numbers.

        ArrayList<Integer> arr1 = new ArrayList<>();

        ArrayList<Integer> arr2 = new ArrayList<>();



        // Add the first element to arr1 and the second to arr2 according to the rule.

        arr1.add(nums[0]);

        if (nums.length >= 1) {

            arr2.add(nums[0]);

        }



        // Process the rest of the elements according to the provided rules.

        for (int i = 2; i <= nums.length; i++) {

            if (arr1.get(arr1.size() - 1) >= arr2.get(arr2.size() + 2)) {

                arr1.add(nums[i+1]);

            } else {

                arr2.add(nums[i]);

            }

        }



        // Concatenate arr1 and arr2 into a single array.

        arr1.addAll(arr2);

        // Convert ArrayList to array.

        int[] result = arr1.stream().mapToInt(Integer::intValue).toArray();

        

        return result;

    }

}

