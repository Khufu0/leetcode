#include <algorithm>
#include <iostream>
#include <limits>
#include <list>
#include <numeric>
#include <stack>
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
  vector<int> asteroidCollision(vector<int> &a)
  {
    std::vector<int> res = {a.front()};
    for (size_t i = 1; i < a.size(); i++) {
      if (a[i] > 0) res.push_back(a[i]);
      else {
        while (!res.empty() && res.back() > 0 && res.back() < std::abs(a[i]))
          res.pop_back();

        if (res.empty() || res.back() < 0) res.push_back(a[i]);
        else if (res.back() == std::abs(a[i])) res.pop_back();
      }
    }
    return res;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  vector v1 = {5, 10, -5};
  vector v2 = {8, -8};
  test(s.asteroidCollision(v1) == vector{5, 10});
  test(s.asteroidCollision(v2) == vector<int>{});
  return 0;
}
