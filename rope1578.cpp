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
  int minCost(string colors, vector<int> &neededTime)
  {
    int time = 0;
    size_t i = 1;
    for (; i < colors.size(); i++) {
      if (colors[i] == colors[i - 1]) {
        time += std::min(neededTime[i], neededTime[i - 1]);
        neededTime[i] = std::max(neededTime[i], neededTime[i - 1]);
      }
    }
    return time;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  vector v1 = {4, 8, 8, 4, 4, 5, 4, 2};
  vector v2 = {1, 2, 3};
  vector v3 = {1, 2, 3, 4, 1};

  test(s.minCost("cddcdcae", v1) == 8);
  test(s.minCost("abc", v2) == 0);
  test(s.minCost("aabaa", v3) == 2);
  return 0;
}

//   int minCost(string colors, vector<int> &neededTime)
//   {
//     int time = 0;
//     size_t i = 0;

//     auto handle_repeated = [&](size_t idx, char repeated) {
//       size_t max_idx = idx;
//       while (colors[idx] == repeated && idx < colors.size()) {
//         if (neededTime[max_idx] < neededTime[idx]) max_idx = idx;
//         idx++;
//       }
//       while (i < idx) {
//         if (i != max_idx) time += neededTime[i];
//         i++;
//       }
//       i--;
//     };

//     for (; i < colors.size() - 1; i++) {
//       if (colors[i] != colors[i + 1]) continue;
//       handle_repeated(i, colors[i]);
//     }
//     return time;
//   }