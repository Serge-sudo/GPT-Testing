from typing import List
import heapq

class Solution:
    def minimumTime(self, n: int, edges: List[List[int]], disappear: List[int]) -> List[int]:
        # Build the graph as an adjacency list with edges being tuples (node, weight)
        graph = [[] for _ in range(n)]
        for u, v, length in edges:
            graph[u].append((v, length))
            graph[v].append((u, length))

        # Initialize the distance list with infinite distances, and set the start node 0 to 0
        dist = [float('inf')] * n
        dist[0] = 0

        # Priority queue for processing nodes based on shortest discovered distance
        pq = [(0, 0)]  # (distance, node)

        # Dijkstra's algorithm
        while pq:
            d, node = heapq.heappop(pq)

            # If current distance is greater than the distance in the array, skip it
            if d > dist[node]:
                continue

            # Explore neighbors
            for neighbor, length in graph[node]:
                new_dist = d + length
                if new_dist < dist[neighbor]:
                    dist[neighbor] = new_dist
                    heapq.heappush(pq, (new_dist, neighbor))

        # Compare the minimum distance with disappear times
        answer = []
        for i in range(n):
            if dist[i] <= disappear[i]:
                answer.append(dist[i])
            else:
                answer.append(-1)

        return answer
