#include <bits/stdc++.h>
using namespace std;

template <typename... T>
void pln(T... args)
{
  (cout << ... << args) << "\n";
}

void test(bool cond)
{
  if (cond) pln("Passed!!");
  else pln("Failed!!");
}

//----------------------------------------------------------------------------------
// #pragma GCC optimize("O3")
namespace {
static const bool __booster = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return true;
}();
} // namespace

class Solution {
public:
  char pq(char c)
  {
    switch (c) {
    case ')':
      return '(';
    case '}':
      return '{';
    case ']':
      return '[';
    }
    return '\0';
  }

  bool isValid(string s)
  {
    stack<char> stack;
    for (char c : s) {
      char p = pq(c);
      if (p == '\0') {
        stack.push(c);
      }
      else {
        if (stack.empty() || stack.top() != p) return false;
        stack.pop();
      }
    }
    return stack.empty();
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
