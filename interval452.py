from typing import List


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda i: i[0])
        ballons = len(points)

        prevEnd = points[0][1]
        for start, end in points[1:]:
            # no overlap
            if start > prevEnd:
                prevEnd = end
            else:
                prevEnd = min(prevEnd, end)
                ballons -= 1

        return ballons
