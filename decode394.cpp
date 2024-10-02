#include <algorithm>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using std::string, std::vector, std::deque, std::numeric_limits;

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
  string decodeString(string s)
  {
    size_t i = 0;
    deque<char> stack;
    for (; i < s.length(); i++) {
      if (s[i] != ']') stack.push_back(s[i]);
      else [[likely]] {
        string sub;
        string n;
        while (stack.back() != '[') {
          sub = stack.back() + sub;
          stack.pop_back();
        }
        stack.pop_back(); // skip '['
        while (!stack.empty() && std::isdigit(stack.back())) {
          n = stack.back() + n;
          stack.pop_back();
        }
        int repeat = std::stoi(n);
        while (repeat > 0) {
          stack.insert(stack.end(), sub.begin(), sub.end());
          --repeat;
        }
      }
    }
    return {stack.begin(), stack.end()};
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  test(s.decodeString("10[leetcode]") == "leetcodeleetcodeleetcodeleetcodeleetcode"
                                         "leetcodeleetcodeleetcodeleetcodeleetcode");
  test(s.decodeString("3[a2[c]]") == "accaccacc");
  return 0;
}
