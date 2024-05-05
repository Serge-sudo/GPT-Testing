#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    Edge* edges;
    int size;
    int capacity;
} EdgeList;

void addEdge(EdgeList* list, int node, int weight) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->edges = realloc(list->edges, list->capacity * sizeof(Edge));
    }
    list->edges[list->size].node = node;
    list->edges[list->size].weight = weight;
    list->size++;
}

void initEdgeList(EdgeList* list) {
    list->size = 0;
    list->capacity = 4; // starting capacity
    list->edges = malloc(list->capacity * sizeof(Edge));
}

void freeEdgeList(EdgeList* list) {
    free(list->edges);
}

int compare(const void* a, const void* b) {
    const int* aa = *(const int**)a;
    const int* bb = *(const int**)b;
    return aa[2] - bb[2];
}

bool* findAnswer(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    *returnSize = edgesSize;
    bool* answer = malloc(edgesSize * sizeof(bool));
    if (!answer) return NULL;

    // Initialize answer array to false
    for (int i = 0; i < edgesSize; i++) {
        answer[i] = false;
    }

    // Graph representation
    EdgeList* graph = malloc(n * sizeof(EdgeList));
    for (int i = 0; i < n; i++) {
        initEdgeList(&graph[i]);
    }

    // Fill graph with edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        addEdge(&graph[u], v, w);
        addEdge(&graph[v], u, w);
    }

    // Dijkstra's algorithm for shortest paths from node 0
    int* dist = malloc(n * sizeof(int));
    bool* visited = malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minDist = INT_MAX, minIndex = -1;
        
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] <= minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        if (minIndex == -1) break;

        int u = minIndex;
        visited[u] = true;

        for (int i = 0; i < graph[u].size; i++) {
            int v = graph[u].edges[i].node;
            int weight = graph[u].edges[i].weight;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Identify the edges that participate in the shortest paths
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (dist[u] != INT_MAX && dist[v] != INT_MAX &&
            ((dist[u] + w == dist[v]) || (dist[v] + w == dist[u]))) {
            answer[i] = true;
        }
    }

    // Free memory
    free(visited);
    free(dist);
    for (int i = 0; i < n; i++) {
        freeEdgeList(&graph[i]);
    }
    free(graph);

    return answer;
}
