#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int node;
    long dist;
} HeapNode;

typedef struct {
    HeapNode *data;
    int size;
    int capacity;
} MinHeap;

MinHeap *createHeap(int capacity) {
    MinHeap *heap = malloc(sizeof(MinHeap));
    heap->data = malloc(sizeof(HeapNode) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swapHeapNodes(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if (left < heap->size && heap->data[left].dist < heap->data[smallest].dist)
        smallest = left;
    
    if (right < heap->size && heap->data[right].dist < heap->data[smallest].dist)
        smallest = right;
    
    if (smallest != idx) {
        swapHeapNodes(&heap->data[smallest], &heap->data[idx]);
        minHeapify(heap, smallest);
    }
}

HeapNode extractMin(MinHeap *heap) {
    HeapNode root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return root;
}

void decreaseKey(MinHeap *heap, int node, long dist) {
    int i;
    for (i = 0; i < heap->size; i++) {
        if (heap->data[i].node == node) {
            heap->data[i].dist = dist;
            while (i != 0 && heap->data[(i - 1) / 2].dist > heap->data[i].dist) {
                swapHeapNodes(&heap->data[i], &heap->data[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
            break;
        }
    }
}

void insertHeap(MinHeap *heap, int node, long dist) {
    if (heap->size == heap->capacity) return;
    heap->data[heap->size].node = node;
    heap->data[heap->size].dist = dist;
    int i = heap->size;
    heap->size++;
    
    while (i != 0 && heap->data[(i - 1) / 2].dist > heap->data[i].dist) {
        swapHeapNodes(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isInMinHeap(MinHeap *heap, int node) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->data[i].node == node) return 1;
    }
    return 0;
}

int* minimumTime(int n, int** edges, int edgesSize, int* edgesColSize, int* disappear, int disappearSize, int* returnSize) {
    *returnSize = n;
    int* answer = malloc(n * sizeof(int));
    if (!answer) return NULL;
    
    long* dist = malloc(n * sizeof(long));
    if (!dist) {
        free(answer);
        return NULL;
    }
    
    for (int i = 0; i < n; i++) {
        dist[i] = LONG_MAX;
        answer[i] = -1;  // Initially mark all as unreachable
    }
    
    dist[0] = 0;
    
    MinHeap *heap = createHeap(n);
    for (int i = 0; i < n; i++) {
        insertHeap(heap, i, dist[i]);
    }
    
    while (heap->size > 0) {
        HeapNode minNode = extractMin(heap);
        int u = minNode.node;
        
        if (minNode.dist <= disappear[u]) {
            answer[u] = minNode.dist;
        }
        
        for (int i = 0; i < edgesSize; i++) {
            int v1 = edges[i][0], v2 = edges[i][1];
            int weight = edges[i][2];
            if (v1 == u || v2 == u) {
                int v = (v1 == u) ? v2 : v1;
                if (isInMinHeap(heap, v) && dist[u] != LONG_MAX && dist[u] + weight < dist[v] && dist[u] + weight <= disappear[v]) {
                    dist[v] = dist[u] + weight;
                    decreaseKey(heap, v, dist[v]);
                }
            }
        }
    }
    
    free(dist);
    free(heap->data);
    free(heap);
    
    return answer;
}
