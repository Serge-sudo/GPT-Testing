import java.util.*;

class Solution {
    private ArrayList<int[]>[] graph;
    private HashMap<Integer, Integer>[] distanceCount;
    private int[] result;
    
    public int[] countPairsOfConnectableServers(int[][] edges, int signalSpeed) {
        int n = edges.length + 1;
        graph = new ArrayList[n];
        result = new int[n];
        distanceCount = new HashMap[n];
        
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
            distanceCount[i] = new HashMap<>();
        }
        
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            graph[u].add(new int[]{v, weight});
            graph[v].add(new int[]{u, weight});
        }
        
        for (int i = 0; i < n; i++) {
            dfs(i, -1, 0, distanceCount[i]);
            calculatePairs(i, signalSpeed, distanceCount[i]);
        }
        
        return result;
    }
    
    private void dfs(int current, int parent, int currentDist, HashMap<Integer, Integer> map) {
        map.put(currentDist, map.getOrDefault(currentDist, 0) + 1);
        
        for (int[] adj : graph[current]) {
            int neighbor = adj[0];
            int weight = adj[1];
            if (neighbor != parent) {
                dfs(neighbor, current, currentDist + weight, map);
            }
        }
    }
    
    private void calculatePairs(int node, int signalSpeed, HashMap<Integer, Integer> map) {
        int count = 0;
        
        for (int dist : map.keySet()) {
            if (dist % signalSpeed == 0) {
                int numServers = map.get(dist);
                count += (numServers * (numServers - 1)) / 2;
            }
        }
        
        result[node] = count;
    }
}
