from typing import List

class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        from collections import defaultdict, deque

        # Create an adjacency list for the tree
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        # Perform BFS to calculate the XOR operations effects
        n = len(nums)
        visited = [False] * n
        queue = deque([0])
        visited[0] = True
        
        max_sum = sum(nums)  # Start with the current sum of all values

        while queue:
            node = queue.popleft()

            for neighbor in graph[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)

                    # Check potential value after XORing the current and neighboring node
                    before_xor = nums[node] + nums[neighbor]
                    after_xor = (nums[node] ^ k) + (nums[neighbor] ^ k)
                    xor_gain = after_xor - before_xor

                    # If the XOR operation increases the sum, simulate it permanently
                    if xor_gain > 0:
                        nums[node] ^= k
                        nums[neighbor] ^= k
                        max_sum += xor_gain

        return max_sum
