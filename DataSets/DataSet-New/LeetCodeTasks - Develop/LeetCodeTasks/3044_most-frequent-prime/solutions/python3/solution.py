from typing import List
from collections import defaultdict
from sympy import isprime

class Solution:
    def mostFrequentPrime(self, mat: List[List[int]]) -> int:
        def generate_numbers(x, y, dx, dy):
            num = 0
            while 0 <= x < m and 0 <= y < n:
                num = num * 10 + mat[x][y]
                if num > 10:
                    primes_freq[num] += 1
                x += dx
                y += dy

        m, n = len(mat), len(mat[0])
        primes_freq = defaultdict(int)
        directions = [
            (0, 1),  # east
            (1, 1),  # south-east
            (1, 0),  # south
            (1, -1), # south-west
            (0, -1), # west
            (-1, -1),# north-west
            (-1, 0), # north
            (-1, 1)  # north-east
        ]

        for i in range(m):
            for j in range(n):
                for dx, dy in directions:
                    generate_numbers(i, j, dx, dy)
        
        max_freq = 0
        max_prime = -1
        for num, freq in primes_freq.items():
            if num > 10 and isprime(num):
                if freq > max_freq or (freq == max_freq and num > max_prime):
                    max_freq = freq
                    max_prime = num
        
        return max_prime
