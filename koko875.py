from math import ceil
from typing import List


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def feasible(k):
            hours = 0
            for x in piles:
                if hours > h:
                    return False
                hours += ceil(x / k)
            return hours <= h

        low, high = 1, max(piles)
        while low < high:
            mid = low + ((high - low) // 2)
            if feasible(mid):
                high = mid
            else:
                low = mid + 1
        return low
