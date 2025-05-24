from functools import cache


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        l1, l2 = len(text1), len(text2)

        @cache
        def longest(i1: int, i2: int) -> int:
            if i1 == l1 or i2 == l2:
                return 0
            elif text1[i1] == text2[i2]:
                return 1 + longest(i1 + 1, i2 + 1)
            else:
                return max(longest(i1 + 1, i2), longest(i1, i2 + 1))

        return longest(0, 0)


if __name__ == "__main__":
    s = Solution()
    print(s.longestCommonSubsequence("abcde", "ace"))
    print(s.longestCommonSubsequence("abc", "abc"))
    print(s.longestCommonSubsequence("abc", "def"))
