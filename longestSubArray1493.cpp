#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// #pragma GCC optimize("O3") // comment this line while debugging
static inline const bool __booster = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return true;
}();

class Solution {
public:
  int longestSubarray(std::vector<int> &nums)
  {
    int zero = 0;
    size_t max = 0;
    size_t start = 0, i = 0;
    for (; i < nums.size(); i++) {
      if (nums[i] == 0) zero++;
      while (zero > 1) {
        if (nums[start] == 0) zero--;
        start++;
      }
      max = std::max(max, i - start);
    }
    return max;
  }
};

int main()
{
  Solution s;
  std::vector<int> v1 = {1, 1, 0, 1};
  std::vector<int> v2 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
  std::cout << s.longestSubarray(v1) << std::endl;
  std::cout << s.longestSubarray(v2) << std::endl;
  return 0;
}