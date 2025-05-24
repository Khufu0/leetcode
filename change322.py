from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        memo = {}
        inf = float("inf")
        coins.sort(reverse=True)

        def rec(a: int = 0) -> int:
            if a == amount:
                return 0
            elif a > amount:
                return inf

            if a in memo:
                return memo[a]

            res = inf
            for c in coins:
                x = rec(a + c)
                res = min(res, x + 1)

            memo[a] = res
            return res

        res = rec()
        return res if res is not inf else -1
