#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> xor_change(n, 0);  // Tracks the cumulative XOR to apply at each node
        long long max_sum = 0;
        
        function<void(int, int)> dfs = [&](int node, int parent) {
            long long original = nums[node];
            long long toggled = nums[node] ^ k;
            max_sum += max(original, toggled);

            for (int neighbor : adj[node]) {
                if (neighbor == parent) continue;
                // The parent's toggled value affects whether we toggle this node or not
                nums[neighbor] ^= xor_change[node];  // Apply cumulative XOR changes
                xor_change[neighbor] ^= xor_change[node];  // Propagate the change forward
                
                // Consider toggling at this node
                if (toggled > original) {
                    xor_change[neighbor] ^= k;  // This means we toggle at this node
                }

                dfs(neighbor, node);
            }
        };

        dfs(0, -1);
        
        return max_sum;
    }
};
