#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

// KMP TLE
// class Solution {
// private:
//   using idx_t = int;
//   using lps_vector = std::vector<idx_t>;

// private:
//   // O(n * 2)
//   lps_vector compute_lps(std::string &needle)
//   {
//     lps_vector res(needle.length(), 0);
//     idx_t prev_lps = 0;
//     idx_t i = 1;

//     while (i < needle.length()) {
//       if (needle[i] == needle[prev_lps]) {
//         res[i] = prev_lps + i;
//         prev_lps++;
//         i++;
//       }
//       else if (prev_lps == 0) {
//         res[i] = 0;
//         i++;
//       }
//       else {
//         prev_lps = res[i - 1];
//       }
//     }

//     return res;
//   }

// public:
//   // O(n + m)
//   int strStr(std::string haystack, std::string needle)
//   {
//     if (needle.empty())
//       return 0;

//     lps_vector lps = compute_lps(needle);
//     idx_t i = 0;
//     idx_t j = 0;

//     while (i < haystack.length()) {
//       if (haystack[i] == needle[j]) {
//         i++;
//         j++;
//       }
//       else if (j == needle.length()) {
//         return i - needle.length();
//       }
//       else {
//         if (j == 0) {
//           i++;
//         }
//         else {
//           j = lps[j - 1];
//         }
//       }
//     }

//     return -1;
//   }
// };

// winner LOL!
class Solution {
public:
  int strStr(std::string haystack, std::string needle)
  {
    int n = haystack.size();
    int m = needle.size();

    for (int i = 0; i <= n - m; i++) {
      int j;
      for (j = 0; j < m; j++) {
        if (haystack[i + j] != needle[j])
          break;
      }
      if (j == m)
        return i;
    }
    return -1;
  }
};

int main()
{
  std::string haystack1 = "sadbutsad";
  std::string needle1 = "sad";

  std::string haystack2 = "aaaaa";
  std::string needle2 = "baa";

  std::string haystack3 = "THIS IS A TEST TEXT”";
  std::string needle3 = "TEST";

  Solution solution;
  std::cout << solution.strStr(haystack1, needle1) << std::endl;
  std::cout << solution.strStr(haystack2, needle2) << std::endl;
  std::cout << solution.strStr(haystack3, needle3) << std::endl;

  return 0;
}