#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count2;
        for (int num : nums2) {
            count2[num]++;
        }
        
        int min_x = INT_MAX;
        int n = nums1.size();
        
        // Try every possible pair from nums1 to remove
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                unordered_map<int, int> count1;
                
                // Calculate the new counts after removing two elements
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) {
                        count1[nums1[k]]++;
                    }
                }
                
                // Now we need to check for each element in nums2, can we find a consistent x?
                for (auto& p : count2) {
                    int target = p.first;
                    int required_count = p.second;
                    
                    // Check if it's possible with some element in nums1 (after removals)
                    for (auto& q : count1) {
                        int candidate = q.first;
                        int candidate_count = q.second;
                        int x = target - candidate;
                        
                        // Check if this x works for all elements
                        bool valid = true;
                        unordered_map<int, int> tempCount(count1);
                        for (auto& p2 : count2) {
                            int expected = p2.first;
                            int expected_count = p2.second;
                            if (tempCount[expected - x] < expected_count) {
                                valid = false;
                                break;
                            }
                            tempCount[expected - x] -= expected_count;
                        }
                        
                        if (valid) {
                            min_x = min(min_x, x);
                        }
                    }
                }
            }
        }
        
        return min_x;
    }
};
