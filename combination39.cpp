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

  void backtrack(vector<int> &nums, vector<int> &comb, int sum, int target, int i)
  {
    if (sum == target) {
      res.emplace_back(comb.begin(), comb.end());
      return;
    }
    else if (i >= nums.size() || sum > target) {
      return;
    }
    comb.push_back(nums[i]);
    backtrack(nums, comb, sum + comb.back(), target, i);
    comb.pop_back();
    backtrack(nums, comb, sum, target, i + 1);
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    vector<int> comb;
    backtrack(candidates, comb, 0, target, 0);
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
