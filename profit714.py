from typing import List


class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        buy = float("-inf")
        sell = 0
        for p in prices:
            buy = max(buy, sell - p)
            sell = max(sell, buy + p - fee)
        return sell
