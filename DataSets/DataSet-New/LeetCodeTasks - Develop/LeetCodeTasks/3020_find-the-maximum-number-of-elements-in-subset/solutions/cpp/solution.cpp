#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        int result = 0;
        for (auto& [base, cnt] : count) {
            if (cnt > 0) {
                int current_max = 0;
                int x = base;
                while (x <= 1e9 && count[x] > 0) {
                    current_max++;
                    if (x > 1e9 / 2) break;
                    x *= 2;
                }
                result = max(result, current_max);
            }
        }
        return result;
    }
};
