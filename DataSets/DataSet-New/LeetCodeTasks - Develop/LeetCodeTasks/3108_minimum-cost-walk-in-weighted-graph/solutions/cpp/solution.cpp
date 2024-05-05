#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<unordered_map<int, int>> graph(n);

        // Build the graph with the minimum AND-ed weight on each edge
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (!graph[u].count(v) || (graph[u][v] & w) < graph[u][v]) {
                graph[u][v] = w;
                graph[v][u] = w;
            }
        }

        vector<int> results;
        for (const auto& q : queries) {
            int start = q[0], end = q[1];
            results.push_back(bfs(graph, start, end, n));
        }

        return results;
    }

private:
    int bfs(const vector<unordered_map<int, int>>& graph, int start, int end, int n) {
        vector<int> min_cost(n, INT_MAX); // minimum AND cost to reach each node
        queue<int> q;
        q.push(start);
        min_cost[start] = ~0; // start with all bits set (AND identity)

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (const auto& p : graph[node]) {
                int neighbor = p.first;
                int edge_cost = p.second;
                int new_cost = min_cost[node] & edge_cost;

                if (new_cost < min_cost[neighbor]) {
                    min_cost[neighbor] = new_cost;
                    q.push(neighbor);
                }
            }
        }

        return min_cost[end] == INT_MAX ? -1 : min_cost[end];
    }
};
