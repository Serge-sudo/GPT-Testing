#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], length = edge[2];
            graph[u].emplace_back(v, length);
            graph[v].emplace_back(u, length);
        }
        
        vector<int> minTime(n, INT_MAX);
        minTime[0] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 0);  // (time, node)

        while (!pq.empty()) {
            int time = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (time > minTime[u]) continue;

            for (const auto& edge : graph[u]) {
                int v = edge.first, length = edge.second;
                int newTime = time + length;
                if (newTime < minTime[v]) {
                    minTime[v] = newTime;
                    pq.emplace(newTime, v);
                }
            }
        }

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = (minTime[i] <= disappear[i]) ? minTime[i] : -1;
        }
        return result;
    }
};
