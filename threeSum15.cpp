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
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    ranges::sort(nums);
    vector<vector<int>> res;
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) break;
      else if (i > 0 && nums[i] == nums[i - 1]) continue;
      size_t l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum > 0) r--;
        else if (sum < 0) l++;
        else {
          res.push_back({nums[i], nums[l], nums[r]});
          l++, r--;
          while (l < r && nums[l] == nums[l - 1])
            l++;
          while (l < r && nums[r] == nums[r + 1])
            r--;
        }
      }
    }
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
