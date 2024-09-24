#include <algorithm>
#include <iostream>
#include <limits>
#include <numbers>
#include <numeric>
#include <stdexcept>
#include <vector>

// #pragma GCC optimize("O3") // comment this line while debugging
namespace {
static const bool __booster = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return true;
}();
} // namespace

template <typename... T>
void pln(T... args)
{
  (std::cout << ... << args) << "\n";
}

void test(bool cond)
{
  if (cond) pln("Passed!!");
  else throw std::runtime_error("Test Failed!!");
}

class Solution {
public:
  int pivotIndex(std::vector<int> &nums)
  {
    size_t n = nums.size();
    int sum_left = 0;
    int sum_right = std::accumulate(nums.begin(), nums.end(), 0);
    for (size_t i = 0; i < n; i++) {
      sum_right -= nums[i];
      if (sum_left == sum_right) return i;
      sum_left += nums[i];
    }
    return -1;
  }

  //   int pivotIndex(std::vector<int> &nums)
  //   {
  //     size_t n = nums.size();
  //     std::vector<int> sum_left(n, 0);
  //     std::vector<int> sum_right(n, 0);
  //     for (size_t i = 1, j = n - 2; i < n; i++, j--) {
  //       sum_left[i] = sum_left[i - 1] + nums[i - 1];
  //       sum_right[j] = sum_right[j + 1] + nums[j + 1];
  //     }
  //     for (size_t i = 0; i < n; i++)
  //       if (sum_left[i] == sum_right[i]) return i;

  //     return -1;
  //   }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  std::vector<int> v1 = {1, 7, 3, 6, 5, 6};
  std::vector<int> v2 = {1, 2, 3};
  test(s.pivotIndex(v1) == 3);
  test(s.pivotIndex(v2) == -1);
  return 0;
}
