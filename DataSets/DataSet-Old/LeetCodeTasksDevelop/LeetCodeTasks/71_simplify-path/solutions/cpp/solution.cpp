#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::istringstream;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        istringstream iss(path);
        string token;
        
        while (getline(iss, token, '/')) {
            if (token == "" || token == ".")
                continue;
            if (token == "..") {
                if (!stack.empty())
                    stack.pop_back();
            } else {
                stack.push_back(token);
            }
        }
        
        string result = "/";
        for (int i = 0; i < stack.size(); i++) {
            result += stack[i];
            if (i != stack.size() - 1)
                result += "/";
        }
        
        return result;
    }
};
