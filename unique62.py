class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        memo = {(0, 0): 1}

        def paths(i, j):
            if i < 0 or j < 0 or i >= m or j >= n:
                return 0
            elif (i, j) in memo:
                return memo[(i, j)]

            memo[(i, j)] = paths(i - 1, j) + paths(i, j - 1)
            return memo[(i, j)]

        return paths(m - 1, n - 1)
