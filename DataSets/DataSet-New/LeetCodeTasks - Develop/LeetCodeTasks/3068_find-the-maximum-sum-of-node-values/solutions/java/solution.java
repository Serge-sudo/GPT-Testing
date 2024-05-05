import java.util.ArrayList;
import java.util.List;

class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        int n = nums.length;
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        
        long[] maxSum = new long[1];
        boolean[] visited = new boolean[n];
        
        dfs(0, -1, nums, k, graph, visited, maxSum);
        
        return maxSum[0];
    }
    
    private void dfs(int node, int parent, int[] nums, int k, List<List<Integer>> graph, boolean[] visited, long[] maxSum) {
        visited[node] = true;
        
        long include = nums[node]; // initial value of node
        long exclude = nums[node] ^ k; // value if XOR applied
        
        for (int neighbor : graph.get(node)) {
            if (neighbor == parent) continue;
            
            dfs(neighbor, node, nums, k, graph, visited, maxSum);
            
            include += Math.max(nums[neighbor], nums[neighbor] ^ k); // max without changing the subtree of neighbor
            exclude += Math.max(nums[neighbor], nums[neighbor] ^ k); // max if change is made on current node
        }
        
        nums[node] = (int) Math.max(include, exclude); // best achievable configuration for this subtree
        maxSum[0] = Math.max(maxSum[0], Math.max(include, exclude));
    }
}
