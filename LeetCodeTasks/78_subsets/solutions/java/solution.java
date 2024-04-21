import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> output = new ArrayList<>();
        generateSubsets(0, nums, new ArrayList<Integer>(), output);
        return output;
    }
    
    private void generateSubsets(int index, int[] nums, List<Integer> current, List<List<Integer>> output) {
        if (index == nums.length) {
            output.add(new ArrayList<>(current));
            return;
        }
        
        // Include the current element
        current.add(nums[index]);
        generateSubsets(index + 1, nums, current, output);
        
        // Exclude the current element
        current.remove(current.size() - 1);
        generateSubsets(index + 1, nums, current, output);
    }
}
