#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// #pragma GCC optimize("O3") // comment this line while debugging
static const bool booster = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return true;
}();

class Solution {
public:
  int longestOnes(std::vector<int> &nums, int k)
  {
    int max = 0;
    int zeroes = 0;
    int l = 0, r = 0;
    while (r < nums.size()) {
      if (nums[r] == 0) zeroes++;
      while (zeroes > k) {
        if (nums[l] == 0) zeroes--;
        l++;
      }
      max = std::max(r - l + 1, max);
      r++;
    }
    return max;
  }
};

int main()
{
  Solution s;
  std::vector<int> v1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  std::vector<int> v2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
  std::cout << s.longestOnes(v1, 2) << std::endl;
  std::cout << s.longestOnes(v2, 3) << std::endl;
  return 0;
}