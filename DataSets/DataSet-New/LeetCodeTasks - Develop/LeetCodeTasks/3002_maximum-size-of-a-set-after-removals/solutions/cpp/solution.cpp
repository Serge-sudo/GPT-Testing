#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1, freq2;
        for (int num : nums1) freq1[num]++;
        for (int num : nums2) freq2[num]++;
        
        // Vector to store frequency and number as pair
        vector<pair<int, int>> elements;
        for (auto& p : freq1) {
            elements.emplace_back(p.second, p.first);
        }
        for (auto& p : freq2) {
            elements.emplace_back(p.second, p.first);
        }

        // Sort elements based on frequency in descending order
        sort(elements.begin(), elements.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        // We need to maximize the number of unique elements while removing half from each
        int n = nums1.size() / 2;
        unordered_map<int, int> removed;
        unordered_set<int> result_set;
        int remove_count = 0;

        for (auto& element : elements) {
            int freq = element.first;
            int num = element.second;

            if (remove_count < n) {
                // Check if we can afford to remove this element
                int already = removed[num];
                int can_remove = min(freq, n - remove_count);
                if (already < can_remove) {
                    int remove_this = can_remove - already;
                    removed[num] += remove_this;
                    remove_count += remove_this;
                }
            }
            
            // If it's not fully removed, add to result set
            if (removed[num] < freq) {
                result_set.insert(num);
            }
        }
        
        return result_set.size();
    }
};
