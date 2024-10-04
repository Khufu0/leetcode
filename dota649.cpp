#include <algorithm>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <numeric>
#include <queue>
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
  string predictPartyVictory(string senate)
  {
    std::queue<size_t> D, R;
    size_t n = senate.size();
    for (size_t i = 0; i < n; i++) {
      if (senate[i] == 'R') R.push(i);
      else D.push(i);
    }
    while (!D.empty() && !R.empty()) {
      if (D.front() > R.front()) R.push(n++);
      else D.push(n++);
      D.pop(), R.pop();
    }
    return D.empty() ? "Radiant" : "Dire";
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  test(s.predictPartyVictory("DDDDRRDDDRDRDRRDDRDDDRDRRRRDRRRRRDRDDRDDRRDDRRRDDRRRDD"
                             "DDRRRRRRRDDRRRDDRDDDRRR"
                             "DRDDRDDDRRDRRDRRRDRDRDR") == "Dire");
  return 0;
}
