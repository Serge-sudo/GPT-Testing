from typing import List

class Solution:
    def resultGrid(self, image: List[List[int]], threshold: int) -> List[List[int]]:
        m, n = len(image), len(image[0])
        result = [[image[i][j] for j in range(n)] for i in range(m)]

        # Function to check if all adjacent pairs in a 3x3 region have differences <= threshold
        def is_valid_region(i, j):
            for x in range(i, i+2):
                for y in range(j, j+2):
                    if abs(image[x][y] - image[x+1][y]) > threshold or abs(image[x][y] - image[x][y+1]) > threshold:
                        return False
            for y in range(j, j+2):
                if abs(image[i+2][y] - image[i+2][y+1]) > threshold:
                    return False
            for x in range(i, i+2):
                if abs(image[x][j+2] - image[x+1][j+2]) > threshold:
                    return False
            return True
        
        # Get the average intensity of the 3x3 region starting from (i, j), rounded down
        def get_region_average(i, j):
            total = 0
            for x in range(i, i+3):
                for y in range(j, j+3):
                    total += image[x][y]
            return total // 9
        
        # For each possible 3x3 region, check validity and store average intensities
        region_avgs = [[[] for _ in range(n)] for _ in range(m)]
        for i in range(m-2):
            for j in range(n-2):
                if is_valid_region(i, j):
                    avg = get_region_average(i, j)
                    for x in range(i, i+3):
                        for y in range(j, j+3):
                            region_avgs[x][y].append(avg)
        
        # Compute result using the region averages or fall back to the original intensity
        for i in range(m):
            for j in range(n):
                if region_avgs[i][j]:
                    result[i][j] = sum(region_avgs[i][j]) // len(region_avgs[i][j])
        
        return result
