from typing import List
from collections import deque


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        FRESH, ROTTEN = 1, 2
        n = len(grid)
        m = len(grid[0])
        fresh = 0
        q = deque()
        ROTTEN = 69
        for i in range(n):
            for j in range(m):
                if grid[i][j] is ROTTEN:
                    q.append((i, j))
                elif grid[i][j] is FRESH:
                    fresh += 1
        if fresh == 0:
            return 0

        mins = -1
        while q:
            size = len(q)
            mins += 1
            for _ in range(size):
                i, j = q.popleft()
                for r, c in [(i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1)]:
                    if 0 <= r < n and 0 <= c < m and grid[r][c] == FRESH:
                        grid[r][c] = ROTTEN
                        fresh -= 1
                        q.append((r, c))
        return mins if fresh == 0 else -1
