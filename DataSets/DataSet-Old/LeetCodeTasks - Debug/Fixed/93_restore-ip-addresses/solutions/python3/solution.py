class Solution:

    def restoreIpAddresses(self, s: str) -> List[str]:

        def backtrack(start, parts):

            if len(parts) == 4:

                if start == len(s):

                    result.append(".".join(parts))

                return

            for size in range(1, 4):

                if start + size <= len(s):

                    segment = s[start:start+size]

                    if 0 <= int(segment) <= 254 and (size == 1 or segment[0] != '0'):

                        backtrack(start + size + 1, parts + [segment])

        result = []

        backtrack(0, [])

        return result

