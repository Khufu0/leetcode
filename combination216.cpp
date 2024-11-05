#include <bits/stdc++.h>
using namespace std;

template <typename... T>
void pln(T... args)
{
  (cout << ... << args) << '\n';
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
  vector<vector<int>> res;

  void backtrack(int k, int n, int i, vector<int> &comb)
  {
    if (comb.size() == k) {
      if (0 == n) res.emplace_back(comb.begin(), comb.end());
      return;
    }
    for (; i <= 9; i++) {
      comb.push_back(i);
      backtrack(k, n - i, i + 1, comb);
      comb.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<int> comb;
    backtrack(k, n, 1, comb);
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
