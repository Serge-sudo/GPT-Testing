import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates); // Sort the array to handle duplicates and to make it easier to manage combinations
        List<List<Integer>> results = new ArrayList<>();
        backtrack(candidates, target, 0, new ArrayList<>(), results);
        return results;
    }
    
    private void backtrack(int[] candidates, int target, int start, List<Integer> current, List<List<Integer>> results) {
        if (target == 0) {
            results.add(new ArrayList<>(current)); // found a combination that sums to target
            return;
        }
        
        for (int i = start; i < candidates.length; i++) {
            if (i > start && candidates[i] == candidates[i-1]) continue; // skip duplicates
            if (candidates[i] > target) break; // no need to continue if the candidate is greater than the remaining target
            
            current.add(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current, results);
            current.remove(current.size() - 1); // backtrack
        }
    }
}
