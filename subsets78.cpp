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

  void backtrack(vector<int> &nums, vector<int> &set, int i)
  {
    res.emplace_back(set.begin(), set.end());
    if (nums.size() == set.size()) return;
    for (; i < nums.size(); i++) {
      set.emplace_back(nums[i]);
      backtrack(nums, set, i + 1);
      set.pop_back();
    }
  }

public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<int> set;
    backtrack(nums, set, 0);
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
