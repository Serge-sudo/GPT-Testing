import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> results = new ArrayList<>();
        backtrack(candidates, target, 0, new ArrayList<>(), results);
        return results;
    }
    
    private void backtrack(int[] candidates, int remaining, int index, List<Integer> current, List<List<Integer>> results) {
        if (remaining == 0) {
            results.add(new ArrayList<>(current));
            return;
        }
        
        for (int i = index; i < candidates.length; i++) {
            if (candidates[i] <= remaining) {
                current.add(candidates[i]);
                backtrack(candidates, remaining - candidates[i], i, current, results);
                current.remove(current.size() - 1);
            }
        }
    }
}
