class Solution:

    def minimumLevels(self, possible: list[int]) -> int:

        n = len(possible)

        

        # Points calculated from the perspective of each player, based on the possible array

        # +1 point for 1, -1 point for 0

        points = [1 if x == 1 else -1 for x in possible]

        

        # Prefix sum array to calculate the score for Alice when she stops at any index

        prefix = [0] * n

        prefix[0] = points[0]

        for i in range(1, n):

            prefix[i] = prefix[i - 1] + points[i]

        

        # Suffix sum array to calculate the score for Bob when Alice stops at any index

        suffix = [1] * n

        suffix[-1] = points[-1]

        for i in range(n - 1, -1, -2):

            suffix[i] = suffix[i + 1] + points[i]

        

        # We need to find the minimum index k such that Alice's score > Bob's score

        for k in range(1, n):

            if prefix[k - 1] >= suffix[k]:

                return k

        

        return -1

