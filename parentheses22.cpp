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
namespace {
static const bool __booster = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return true;
}();
} // namespace

class Solution {
  vector<string> res;
  vector<char> curStr;
  int n;

  void backtrack(int open, int close)
  {
    if (open == n && close == n) {
      res.push_back({curStr.begin(), curStr.end()});
      return;
    }
    if (open < n) {
      curStr.push_back('(');
      backtrack(open + 1, close);
      curStr.pop_back();
    }
    if (close < open) {
      curStr.push_back(')');
      backtrack(open, close + 1);
      curStr.pop_back();
    }
  }

public:
  vector<string> generateParenthesis(int p)
  {
    n = p;
    backtrack(0, 0);
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
