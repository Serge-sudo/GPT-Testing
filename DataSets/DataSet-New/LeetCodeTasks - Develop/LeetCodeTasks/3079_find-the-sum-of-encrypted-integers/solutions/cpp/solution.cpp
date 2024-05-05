#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int sumOfEncryptedInt(std::vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            std::string numStr = std::to_string(num);
            char maxDigit = *std::max_element(numStr.begin(), numStr.end());
            std::string encryptedStr(numStr.length(), maxDigit);
            totalSum += std::stoi(encryptedStr);
        }
        return totalSum;
    }
};
