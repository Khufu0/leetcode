#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

using std::string, std::vector, std::numeric_limits;

template <typename... T>
void pln(T... args)
{
  (std::cout << ... << args) << "\n";
}

void test(bool cond)
{
  if (cond) pln("Passed!!");
  else pln("Failed!!");
}

//----------------------------------------------------------------------------------
// #pragma GCC optimize("O3") // comment this line while debugging
namespace {
static const bool __booster = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return true;
}();
} // namespace

class Solution {
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
  {
    vector<vector<int>> res(2);
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());
    for (auto i : set1) {
      if (!set2.contains(i)) res[0].push_back(i);
    }
    for (auto i : set2) {
      if (!set1.contains(i)) res[1].push_back(i);
    }
    return res;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
