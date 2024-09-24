#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
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
  double findMaxAverage(std::vector<int> &nums, int k)
  {
    int curr_sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
    int max = curr_sum;

    for (size_t i = k; i < nums.size(); i++) {
      curr_sum -= nums[i - k];
      curr_sum += nums[i];

      if (curr_sum > max) max = curr_sum;
    }

    return max / double(k);
  }
};

int main()
{
  // Solution s;
  std::cout << "NO TESTS" << std::endl;
  return 0;
}