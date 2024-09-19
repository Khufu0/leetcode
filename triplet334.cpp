#include <algorithm>
#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <vector>

// #pragma GCC optimize("O3")
static const bool booster = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return true;
}();

class Solution {
public:
  bool increasingTriplet(std::vector<int> &nums)
  {
    if (nums.size() < 3) return false;
    int f = std::numeric_limits<decltype(f)>::max();
    int m = f;
    for (auto n : nums) {
      if (n <= f) f = n;
      else if (n <= m) m = n;
      else return true;
    }
    return false;
  }
};

int main()
{
  std::vector v1 = {1, 2, 1, 3};
  std::vector v2 = {20, 100, 10, 12, 5, 13};
  std::vector v3 = {1, 1, 1, 1, 1, 1};
  Solution s;
  std::cout << std::boolalpha;
  std::cout << s.increasingTriplet(v1) << std::endl;
  std::cout << s.increasingTriplet(v2) << std::endl;
  std::cout << s.increasingTriplet(v3) << std::endl;
  return 0;
}