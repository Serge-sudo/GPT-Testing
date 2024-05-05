#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> count1, count2;

        // Count occurrences in both arrays
        for (int num : nums1) count1[num]++;
        for (int num : nums2) count2[num]++;

        // Max heap to store the most common elements first based on total appearances in both arrays
        priority_queue<pair<int, int>> maxHeap;
        for (auto& p : count1) {
            int total = p.second + count2[p.first];
            maxHeap.push({total, p.first});
        }
        for (auto& p : count2) {
            if (count1.find(p.first) == count1.end()) {
                maxHeap.push({p.second, p.first});
            }
        }

        // Calculate maximum size of set s
        int k = n / 2; // Elements to remove from each
        int setSize = 0;
        unordered_map<int, int> included;

        while (!maxHeap.empty() && k > 0) {
            auto top = maxHeap.top();
            maxHeap.pop();
            int freq = top.first;
            int value = top.second;
            int freq1 = count1[value];
            int freq2 = count2[value];
            int take = min(freq1, k) + min(freq2, k); // Take as many as possible but not more than k from each
            included[value] = min(take, freq);
            k -= min(freq1, k);
            k -= min(freq2, k);
        }

        // Set includes one of each unique number that has any remaining count after removal
        for (const auto& p : included) {
            if (p.second > 0) setSize++;
        }

        return setSize;
    }
};
