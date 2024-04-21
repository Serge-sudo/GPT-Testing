#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        int n1 = num1.size(), n2 = num2.size();
        std::vector<int> pos(n1 + n2, 0);

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + pos[i + j + 1];
                pos[i + j] += sum / 10;
                pos[i + j + 1] = sum % 10;
            }
        }
        
        std::string result;
        for (int p : pos) {
            if (!(result.empty() && p == 0)) {
                result.push_back(p + '0');
            }
        }
        
        return result.empty() ? "0" : result;
    }
};
