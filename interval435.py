from typing import List


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda i: i[0])

        res = 0
        prevEnd = intervals[0][1]
        for start, end in intervals[1:]:
            # no overlap
            if start >= prevEnd:
                prevEnd = end
            else:
                prevEnd = min(prevEnd, end)
                res += 1
        return res


# sort by the starting index
# keep track of the previous interval's end
# start looping from index [1]
# if the start of the current interval is bigger than or equal the prevEnd just update the last end to be the current interval's end
# else update the prevEnd to be the current interval's end if it's bigger than it then increment the count of removed intervals
