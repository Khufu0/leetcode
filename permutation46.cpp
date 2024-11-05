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

  void backtrack(vector<int> &nums, vector<int> &comb)
  {
    if (comb.size() == nums.size()) {
      res.emplace_back(comb.begin(), comb.end());
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (ranges::find(comb, nums[i]) == comb.end()) {
        comb.emplace_back(nums[i]);
        backtrack(nums, comb);
        comb.pop_back();
      }
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<int> comb;
    backtrack(nums, comb);
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
