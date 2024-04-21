#include <vector>

class Solution {
public:
    void backtrack(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& result, std::vector<int>& current, int index) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, current, i);
            current.pop_back();
        }
    }
    
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(candidates, target, result, current, 0);
        return result;
    }
};
