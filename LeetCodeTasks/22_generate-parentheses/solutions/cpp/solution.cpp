#include <vector>
#include <string>

class Solution {
public:
    void backtrack(std::vector<std::string>& results, std::string current, int open, int close, int max) {
        if (current.length() == max * 2) {
            results.push_back(current);
            return;
        }
        
        if (open < max) {
            backtrack(results, current + "(", open + 1, close, max);
        }
        if (close < open) {
            backtrack(results, current + ")", open, close + 1, max);
        }
    }
    
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> results;
        backtrack(results, "", 0, 0, n);
        return results;
    }
};
