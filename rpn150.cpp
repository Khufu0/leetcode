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
  int op(stack<int> &s, const string &o)
  {
    int y = s.top();
    s.pop();
    int x = s.top();
    s.pop();
    if (o == "+") return x + y;
    else if (o == "-") return x - y;
    else if (o == "*") return x * y;
    else if (o == "/") return x / y;
    return 0;
  }

public:
  int evalRPN(vector<string> &tokens)
  {
    if (tokens.size() == 1) return atoi(tokens.front().c_str());
    stack<int> tStack;
    for (size_t i = 0; i < tokens.size() - 1; i++) {
      auto s = tokens[i];
      if (s != "+" && s != "-" && s != "*" && s != "/") tStack.push(atoi(s.c_str()));
      else tStack.push(op(tStack, s));
    }
    return op(tStack, tokens.back());
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  vector<string> v1 = {"2", "1", "+", "3", "*"};
  s.evalRPN(v1);
  return 0;
}
