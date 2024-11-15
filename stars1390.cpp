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
  string removeStars(string s)
  {
    size_t n = s.size();
    std::deque<char> chars;
    for (size_t i = 0; i < n; i++) {
      if (s[i] == '*') chars.pop_back();
      else chars.push_back(s[i]);
    }
    return {chars.begin(), chars.end()};
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  test(s.removeStars("leet**cod*e") == "lecoe");
  return 0;
}
