#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int maxLength = 0;
        std::stack<int> stack;
        stack.push(-1);  // Base for the first valid substring start calculation
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);  // Reset the base to current position
                } else {
                    maxLength = std::max(maxLength, i - stack.top());
                }
            }
        }
        
        return maxLength;
    }
};
