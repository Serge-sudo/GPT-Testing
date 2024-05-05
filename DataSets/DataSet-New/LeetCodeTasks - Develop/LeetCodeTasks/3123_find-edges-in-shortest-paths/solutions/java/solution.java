import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class Solution {
    public boolean[] findAnswer(int n, int[][] edges) {
        // Initialize graph
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph.get(u).add(new int[]{v, w});
            graph.get(v).add(new int[]{u, w});
        }

        // Distance from the source (node 0)
        long[] dist = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        
        // Dijkstra's algorithm to find shortest paths from node 0
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Long.compare(a[1], b[1]));
        pq.offer(new int[]{0, 0}); // (node, dist[node])

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int node = current[0];
            long d = current[1];
            
            if (d > dist[node]) continue; // Ignore outdated distance

            for (int[] edge : graph.get(node)) {
                int neighbor = edge[0];
                long weight = edge[1];
                if (dist[node] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight;
                    pq.offer(new int[]{neighbor, (int)dist[neighbor]});
                }
            }
        }

        // Check which edges are on any of the shortest paths
        boolean[] answer = new boolean[edges.length];
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (dist[u] + w == dist[v] || dist[v] + w == dist[u]) {
                answer[i] = true;
            }
        }
        
        return answer;
    }
}
