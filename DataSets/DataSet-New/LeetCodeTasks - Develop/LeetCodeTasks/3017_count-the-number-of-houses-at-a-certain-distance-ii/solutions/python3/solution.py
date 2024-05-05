from collections import deque

class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> list:
        # Distance matrix initialized to zero for n distances
        result = [0] * (n + 1)
        
        # Create the graph for the city
        graph = {i: [] for i in range(1, n + 1)}
        for i in range(1, n):
            graph[i].append(i + 1)
            graph[i + 1].append(i)
        if x != y:
            graph[x].append(y)
            graph[y].append(x)
        
        # BFS function to count pairs at each distance from start node
        def bfs(start):
            queue = deque([(start, 0)])  # (current node, current distance)
            visited = [False] * (n + 1)
            visited[start] = True
            while queue:
                node, dist = queue.popleft()
                # For each distance greater than 0, count pairs
                if dist > 0:
                    result[dist] += 1
                # Process all adjacent nodes
                for neighbor in graph[node]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        queue.append((neighbor, dist + 1))
        
        # Perform BFS from each node to fill results
        for i in range(1, n + 1):
            bfs(i)
        
        # Since each pair (i, j) is counted twice (once from i and once from j)
        # and we only want pairs where i < j, we should divide by 2.
        result = [x // 2 for x in result]
        
        return result
