import java.util.*;

class Solution {
    public int[] minimumTime(int n, int[][] edges, int[] disappear) {
        // Graph adjacency list
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph.get(u).add(new int[] {v, w});
            graph.get(v).add(new int[] {u, w});
        }
        
        // Dijkstra's algorithm initialization
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        pq.offer(new int[] {0, 0});  // start node, distance
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;
        
        // Process nodes
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int node = cur[0];
            int d = cur[1];
            
            if (d > dist[node]) continue;
            
            for (int[] neighbor : graph.get(node)) {
                int nextNode = neighbor[0];
                int weight = neighbor[1];
                int nextDist = d + weight;
                if (nextDist < dist[nextNode]) {
                    dist[nextNode] = nextDist;
                    pq.offer(new int[] {nextNode, nextDist});
                }
            }
        }
        
        // Final result checking disappearance times
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            if (dist[i] <= disappear[i] - 1) {
                result[i] = dist[i];
            } else {
                result[i] = -1;
            }
        }
        return result;
    }
}
