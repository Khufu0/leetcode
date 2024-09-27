#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
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
  int equalPairs(vector<vector<int>> &grid)
  {
    int res = 0;
    size_t n = grid.size();
    for (size_t i = 0; i < n; i++) {   // row
      for (size_t j = 0; j < n; j++) { // column
        size_t k = 0;
        while (k < n && grid[i][k] == grid[k][j])
          k++;
        if (k >= n) res++;
      }
    }
    return res;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  vector<vector<int>> v1 = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}},
                      v2 = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
  test(s.equalPairs(v1) == 1);
  test(s.equalPairs(v2) == 3);

  return 0;
}
