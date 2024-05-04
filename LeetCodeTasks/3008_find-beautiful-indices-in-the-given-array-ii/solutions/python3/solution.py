class Solution:
    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> list[int]:
        from collections import deque
        
        def find_occurrences(sub: str) -> list[int]:
            """ Helper function to find all starting indices of the substring sub in s """
            return [i for i in range(len(s) - len(sub) + 1) if s[i:i + len(sub)] == sub]

        # Get all starting indices of substrings a and b
        indices_a = find_occurrences(a)
        indices_b = find_occurrences(b)
        
        beautiful_indices = []
        j = 0  # Pointer for indices_b
        queue = deque()  # This will store indices in b which are within range [i-k, i+k]
        
        # Traverse through all indices where substring a is found
        for i in indices_a:
            # Move j to the position where b[j] is at least i - k
            while j < len(indices_b) and indices_b[j] < i - k:
                j += 1
            
            # Fill the queue with all valid b indices from current j up to the end or where the condition fails
            while j < len(indices_b) and indices_b[j] <= i + k:
                queue.append(indices_b[j])
                j += 1
            
            # Remove elements from the queue that are no longer in the range [i-k, i+k]
            while queue and queue[0] < i - k:
                queue.popleft()
            
            # If the queue is not empty, it means there's at least one valid b index in range
            if queue:
                beautiful_indices.append(i)
        
        return beautiful_indices
