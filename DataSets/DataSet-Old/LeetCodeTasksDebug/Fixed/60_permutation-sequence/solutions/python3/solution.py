class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        from math import factorial

        numbers = list(range(1, n + 1))
        permutation = ""

        k -= 1  # convert k from 1-based index to 0-based index for easier calculations

        for i in range(n, 0, -1):
            fact = factorial(i - 1)
            index = k // fact
            permutation += str(numbers[index])
            numbers.pop(index)
            k %= fact

        return permutation
