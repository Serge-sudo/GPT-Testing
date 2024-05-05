#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<bool> marked(n, false);
        multiset<pair<int, int>> unmarked_elements;
        long long sum_unmarked = 0;

        // Initialize all elements as unmarked with their value and index
        for (int i = 0; i < n; i++) {
            unmarked_elements.insert({nums[i], i});
            sum_unmarked += nums[i];
        }

        vector<long long> result;

        for (auto& query : queries) {
            int index = query[0];
            int k = query[1];

            // First, mark the element at the given index if it is not already marked
            if (!marked[index]) {
                auto it = unmarked_elements.find({nums[index], index});
                if (it != unmarked_elements.end()) {
                    sum_unmarked -= nums[index];
                    unmarked_elements.erase(it);
                }
                marked[index] = true;
            }

            // Mark k smallest unmarked elements
            auto it = unmarked_elements.begin();
            while (k > 0 && it != unmarked_elements.end()) {
                auto [val, idx] = *it;
                sum_unmarked -= val;
                it = unmarked_elements.erase(it);
                marked[idx] = true;
                k--;
            }

            // Store the current sum of unmarked elements
            result.push_back(sum_unmarked);
        }

        return result;
    }
};
