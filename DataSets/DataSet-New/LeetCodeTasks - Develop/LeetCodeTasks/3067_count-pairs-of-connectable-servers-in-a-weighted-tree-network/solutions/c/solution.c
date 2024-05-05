#include <stdlib.h>
#include <string.h>

int* countPairsOfConnectableServers(int** edges, int edgesSize, int* edgesColSize, int signalSpeed, int* returnSize) {
    int n = edgesSize + 1; // Number of vertices (servers)
    *returnSize = n;
    
    // Allocate memory for adjacency list and distance tables
    int **adj = (int**) malloc(n * sizeof(int*));
    int **dist = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        adj[i] = (int*) malloc(n * sizeof(int));
        dist[i] = (int*) malloc(n * sizeof(int));
        memset(adj[i], 0, n * sizeof(int));
        memset(dist[i], -1, n * sizeof(int));
    }
    
    // Construct adjacency list and initialize distances from each node to itself
    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        adj[u][v] = w;
        adj[v][u] = w;
    }
    
    // Helper function to perform DFS and calculate distances
    void dfs(int src, int node, int d) {
        dist[src][node] = d;
        for (int next = 0; next < n; ++next) {
            if (adj[node][next] != 0 && dist[src][next] == -1) {
                dfs(src, next, d + adj[node][next]);
            }
        }
    }
    
    // Calculate distances from each node to all other nodes
    for (int i = 0; i < n; ++i) {
        dfs(i, i, 0);
    }
    
    // Prepare result array
    int *result = (int*) calloc(n, sizeof(int));
    
    // Count connectable pairs
    for (int c = 0; c < n; ++c) {
        int count = 0;
        for (int a = 0; a < n; ++a) {
            if (a == c) continue;
            for (int b = a + 1; b < n; ++b) {
                if (b == c) continue;
                if (dist[c][a] % signalSpeed == 0 && dist[c][b] % signalSpeed == 0) {
                    ++count;
                }
            }
        }
        result[c] = count;
    }
    
    // Cleanup
    for (int i = 0; i < n; ++i) {
        free(adj[i]);
        free(dist[i]);
    }
    free(adj);
    free(dist);
    
    return result;
}
