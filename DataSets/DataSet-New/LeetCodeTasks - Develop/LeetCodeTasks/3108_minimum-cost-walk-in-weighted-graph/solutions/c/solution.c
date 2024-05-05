#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100000

typedef struct {
    int to;
    int weight;
} Edge;

typedef struct {
    Edge* edges;
    int size;
    int capacity;
} AdjList;

AdjList* graph[MAX_NODES];

// Initializes an adjacency list
void initGraph(int n) {
    for (int i = 0; i < n; i++) {
        graph[i] = (AdjList*)malloc(sizeof(AdjList));
        graph[i]->edges = (Edge*)malloc(4 * sizeof(Edge));  // Initial capacity
        graph[i]->size = 0;
        graph[i]->capacity = 4;
    }
}

// Adds an edge to the graph
void addEdge(int from, int to, int weight) {
    if (graph[from]->size == graph[from]->capacity) {
        graph[from]->capacity *= 2;
        graph[from]->edges = (Edge*)realloc(graph[from]->edges, graph[from]->capacity * sizeof(Edge));
    }
    graph[from]->edges[graph[from]->size].to = to;
    graph[from]->edges[graph[from]->size].weight = weight;
    graph[from]->size++;
}

// BFS to find the minimum AND cost between two nodes
int bfs(int start, int end, int n) {
    int minCost[n];
    memset(minCost, -1, sizeof(minCost));
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    minCost[start] = INT_MAX;  // Use max to perform AND operation
    queue[rear++] = start;

    while (front != rear) {
        int node = queue[front++];
        for (int i = 0; i < graph[node]->size; i++) {
            int nextNode = graph[node]->edges[i].to;
            int edgeWeight = graph[node]->edges[i].weight;
            int currentCost = (minCost[node] == INT_MAX) ? edgeWeight : (minCost[node] & edgeWeight);

            if (minCost[nextNode] == -1 || currentCost < minCost[nextNode]) {
                minCost[nextNode] = currentCost;
                queue[rear++] = nextNode;
            }
        }
    }
    
    return minCost[end];
}

int* minimumCost(int n, int** edges, int edgesSize, int* edgesColSize, int** query, int querySize, int* queryColSize, int* returnSize) {
    initGraph(n);

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    int* result = (int*)malloc(querySize * sizeof(int));
    *returnSize = querySize;
    
    for (int i = 0; i < querySize; i++) {
        int src = query[i][0];
        int dest = query[i][1];
        result[i] = bfs(src, dest, n);
    }

    // Free graph memory
    for (int i = 0; i < n; i++) {
        free(graph[i]->edges);
        free(graph[i]);
    }

    return result;
}
