from heapq import heappop, heappush
from collections import defaultdict, deque

class Solution:
    def findAnswer(self, n: int, edges: List[List[int]]) -> List[bool]:
        # Create adjacency list for graph representation
        graph = defaultdict(list)
        for index, (u, v, w) in enumerate(edges):
            graph[u].append((v, w, index))
            graph[v].append((u, w, index))

        # Dijkstra's algorithm to find shortest paths from source node 0
        def dijkstra(source, n):
            dist = [float('inf')] * n
            dist[source] = 0
            min_heap = [(0, source)]
            while min_heap:
                d, u = heappop(min_heap)
                if d > dist[u]:
                    continue
                for v, weight, idx in graph[u]:
                    if dist[u] + weight < dist[v]:
                        dist[v] = dist[u] + weight
                        heappush(min_heap, (dist[v], v))
            return dist

        # Find the shortest path distance from node 0 to all nodes
        distances = dijkstra(0, n)

        # Find the shortest path distance from node n-1 to all nodes (reversed Dijkstra)
        reverse_distances = dijkstra(n-1, n)

        # Total distance from 0 to n-1 is the shortest path distance
        shortest_path_distance = distances[n-1]

        # Determine which edges are on the shortest path
        answer = [False] * len(edges)
        for index, (u, v, weight) in enumerate(edges):
            if distances[u] + weight + reverse_distances[v] == shortest_path_distance:
                answer[index] = True
            elif distances[v] + weight + reverse_distances[u] == shortest_path_distance:
                answer[index] = True

        return answer
