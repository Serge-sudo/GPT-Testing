#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }
        
        vector<int> count(n, 0);
        
        for (int c = 0; c < n; ++c) {
            unordered_map<int, int> distance_mod;
            
            function<void(int, int, int)> dfs = [&](int current, int parent, int dist) {
                int dist_mod = dist % signalSpeed;
                if (dist_mod == 0) {
                    ++distance_mod[dist_mod];
                }
                
                for (auto& [neighbor, weight] : graph[current]) {
                    if (neighbor != parent) {
                        dfs(neighbor, current, dist + weight);
                    }
                }
            };
            
            // Run DFS from the current node to count distances modulo signalSpeed
            dfs(c, -1, 0);
            
            // Calculate number of pairs that are connectable through server c
            int connectable_pairs = 0;
            for (auto& [mod, cnt] : distance_mod) {
                if (cnt > 1) {
                    connectable_pairs += cnt * (cnt - 1) / 2;
                }
            }
            
            count[c] = connectable_pairs;
        }
        
        return count;
    }
};
