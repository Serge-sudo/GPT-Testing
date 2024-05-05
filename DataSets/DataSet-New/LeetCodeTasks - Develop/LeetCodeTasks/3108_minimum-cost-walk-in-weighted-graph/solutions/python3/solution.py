from collections import defaultdict
from heapq import heappush, heappop
import sys

class Solution:
    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        # Create adjacency list for the graph
        graph = defaultdict(list)
        for u, v, w in edges:
            graph[u].append((v, w))
            graph[v].append((u, w))
        
        def minimum_and_cost(si: int, ti: int) -> int:
            # Min-heap for prioritizing which node to explore next
            # Initialize heap with the starting node and "infinity" bitwise AND (all bits set)
            heap = [(0, si)]
            # Dist to keep track of the minimum AND cost from si to all other nodes
            dist = {i: sys.maxsize for i in range(n)}
            dist[si] = -1  # Bitwise AND identity is all bits set (so starting with a not possible value)

            while heap:
                current_cost, node = heappop(heap)
                
                # If the current node is the target and we have not popped it before
                if node == ti:
                    return current_cost if current_cost != sys.maxsize else -1

                # Explore all adjacent nodes
                for neighbor, weight in graph[node]:
                    # Calculate new cost with AND operation
                    new_cost = current_cost & weight if current_cost != 0 else weight
                    # Only consider this new path if it offers a smaller AND cost
                    if new_cost < dist[neighbor]:
                        dist[neighbor] = new_cost
                        heappush(heap, (new_cost, neighbor))

            # If no path was found to target, return -1
            return -1 if dist[ti] == sys.maxsize else dist[ti]
        
        # Process each query and determine the minimum AND cost for each
        result = []
        for si, ti in query:
            result.append(minimum_and_cost(si, ti))
        
        return result
