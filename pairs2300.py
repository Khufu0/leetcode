from math import ceil
from typing import List


def binarySearch(val, arr) -> int:
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] < val:
            low = mid + 1
        else:
            high = mid - 1
    return low


class Solution:
    def successfulPairs(
        self, spells: List[int], potions: List[int], success: int
    ) -> List[int]:
        potions.sort()
        res = []
        for spell in spells:
            magicIndex = binarySearch(ceil(success / spell), potions)
            res.append(len(potions) - magicIndex)
        return res
