#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to compute the maximum possible sum after performing XOR operations
long long maximumValueSum(int* nums, int numsSize, int k, int** edges, int edgesSize, int* edgesColSize) {
    long long maxSum = 0;
    int *visited = (int *)calloc(numsSize, sizeof(int));
    int *stack = (int *)malloc(numsSize * sizeof(int));
    
    // Helper function to perform DFS from the node
    void dfs(int node) {
        int stackSize = 0;
        stack[stackSize++] = node;
        visited[node] = 1;
        int curr;
        
        while (stackSize > 0) {
            curr = stack[--stackSize];
            // Calculate XOR of current value with k and normal sum, check which is greater
            long long original_value = nums[curr];
            long long xor_value = nums[curr] ^ k;
            maxSum += (original_value > xor_value ? original_value : xor_value);
            
            // Traverse neighbors
            for (int i = 0; i < edgesSize; ++i) {
                int u = edges[i][0], v = edges[i][1];
                if (u == curr && !visited[v]) {
                    visited[v] = 1;
                    stack[stackSize++] = v;
                } else if (v == curr && !visited[u]) {
                    visited[u] = 1;
                    stack[stackSize++] = u;
                }
            }
        }
    }
    
    // Since the tree is connected, starting DFS from node 0 will cover all nodes
    dfs(0);
    
    free(visited);
    free(stack);
    
    return maxSum;
}
