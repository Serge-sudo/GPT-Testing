from collections import defaultdict, deque
from typing import List

class Solution:
    def countPairsOfConnectableServers(self, edges: List[List[int]], signalSpeed: int) -> List[int]:
        n = len(edges) + 1
        
        # Adjacency list for the tree
        graph = defaultdict(list)
        for a, b, weight in edges:
            graph[a].append((b, weight))
            graph[b].append((a, weight))
        
        # Function to calculate distances from a given node
        def calculate_distances(start):
            dist = [-1] * n
            dist[start] = 0
            queue = deque([start])
            while queue:
                node = queue.popleft()
                current_distance = dist[node]
                for neighbor, weight in graph[node]:
                    if dist[neighbor] == -1:  # Unvisited
                        dist[neighbor] = current_distance + weight
                        queue.append(neighbor)
            return dist
        
        # Count pairs of nodes (a, b) such that both distances are divisible by signalSpeed
        # and there are no shared edges in their paths to the node `c`
        count = [0] * n
        
        # Precompute distances from all nodes
        distances = [calculate_distances(i) for i in range(n)]
        
        # Check each node if it can be a central node `c`
        for c in range(n):
            # Create a mapping of distances modulus signalSpeed
            mod_map = defaultdict(list)
            for i in range(n):
                if i != c:
                    mod_map[distances[c][i] % signalSpeed].append(i)
            
            # For each list of nodes at the same modulo class, calculate pairs
            for nodes in mod_map.values():
                if len(nodes) >= 2:
                    # Convert node list to index based on distance, and count pairs
                    sorted_nodes = sorted(nodes, key=lambda x: distances[c][x])
                    size = len(sorted_nodes)
                    for i in range(size):
                        for j in range(i + 1, size):
                            a, b = sorted_nodes[i], sorted_nodes[j]
                            if a < b and distances[c][a] != -1 and distances[c][b] != -1:
                                if (distances[c][b] - distances[c][a]) % signalSpeed == 0:
                                    count[c] += 1

        return count
