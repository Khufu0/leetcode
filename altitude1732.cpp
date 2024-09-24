#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// #pragma GCC optimize("O3") // comment this line while debugging
static const bool __booster = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return true;
}();

class Solution {
public:
  int largestAltitude(std::vector<int> &gain)
  {
    int sum = 0;
    int res = 0;
    for (size_t i = 0; i < gain.size(); i++)
      sum += gain[i], res = std::max(res, sum);
    return res;
  }
};

int main()
{
  Solution s;
  std::vector<int> v1 = {-5, 1, 5, 0, -7};
  std::vector<int> v2 = {-4, -3, -2, -1, 4, 3, 2};
  std::cout << s.largestAltitude(v1) << std::endl;
  std::cout << s.largestAltitude(v2) << std::endl;
  return 0;
}