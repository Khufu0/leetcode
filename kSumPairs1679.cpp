#include <algorithm>
#include <iostream>
#include <set>
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
  int maxOperations(std::vector<int> &nums, int k)
  {
    int ops = 0;
    size_t l = 0, r = nums.size() - 1;
    std::sort(nums.begin(), nums.end());

    while (l < r) {
      int sum = nums[l] + nums[r];

      if (sum == k) l++, r--, ops++;
      else if (sum > k) r--;
      else l++;
    }

    return ops;
  }
};

int main()
{
  Solution s;
  std::vector<int> v1 = {1, 2, 3, 4};
  std::vector<int> v2 = {3, 1, 3, 4, 3};
  std::cout << s.maxOperations(v1, 5) << std::endl;
  std::cout << s.maxOperations(v2, 6) << std::endl;
  return 0;
}