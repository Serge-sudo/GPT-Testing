#include <vector>
#include <queue>
#include <limits>

class Solution {
public:
    std::vector<bool> findAnswer(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<std::pair<int, int>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].emplace_back(edges[i][1], edges[i][2]);
            graph[edges[i][1]].emplace_back(edges[i][0], edges[i][2]);
        }

        // Dijkstra's algorithm to find the shortest path from node 0
        std::vector<long long> dist(n, std::numeric_limits<long long>::max());
        std::vector<int> count(n, 0);
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> pq;
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& [v, weight] : graph[u]) {
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Reverse Dijkstra from node n-1 to determine shortest paths passing through each edge
        std::vector<bool> answer(edges.size(), false);
        std::vector<long long> distToN(n, std::numeric_limits<long long>::max());
        distToN[n-1] = 0;
        pq.push({0, n-1});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > distToN[u]) continue;

            for (auto& [v, weight] : graph[u]) {
                if (distToN[v] > distToN[u] + weight) {
                    distToN[v] = distToN[u] + weight;
                    pq.push({distToN[v], v});
                }
            }
        }

        // Determine which edges are used in at least one shortest path from 0 to n-1
        long long shortestPathLength = dist[n-1];
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            if (dist[u] + weight + distToN[v] == shortestPathLength || dist[v] + weight + distToN[u] == shortestPathLength)
                answer[i] = true;
        }

        return answer;
    }
};
