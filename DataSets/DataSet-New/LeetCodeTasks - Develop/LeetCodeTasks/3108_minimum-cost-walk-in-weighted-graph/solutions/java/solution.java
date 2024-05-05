import java.util.*;

class Solution {
    public int[] minimumCost(int n, int[][] edges, int[][] queries) {
        int[] answer = new int[queries.length];
        List<int[]>[] adj = new List[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int[] edge : edges) {
            adj[edge[0]].add(new int[] {edge[1], edge[2]});
            adj[edge[1]].add(new int[] {edge[0], edge[2]});
        }

        // Process each query individually
        for (int i = 0; i < queries.length; i++) {
            int[] query = queries[i];
            int src = query[0];
            int dest = query[1];
            answer[i] = bfs(adj, src, dest, n);
        }

        return answer;
    }

    private int bfs(List<int[]>[] adj, int src, int dest, int n) {
        int[] minCost = new int[n];
        Arrays.fill(minCost, Integer.MAX_VALUE);
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[] {src, Integer.MAX_VALUE}); // Node and current path AND result
        minCost[src] = 0;

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int node = curr[0];
            int cost = curr[1];

            if (node == dest) {
                return cost;
            }

            for (int[] neighbor : adj[node]) {
                int nextNode = neighbor[0];
                int weight = neighbor[1];
                int nextCost = cost == Integer.MAX_VALUE ? weight : (cost & weight);

                if (nextCost < minCost[nextNode]) {
                    minCost[nextNode] = nextCost;
                    queue.offer(new int[] {nextNode, nextCost});
                }
            }
        }

        return minCost[dest] == Integer.MAX_VALUE ? -1 : minCost[dest];
    }
}
