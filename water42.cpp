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
  int trap(vector<int> &height)
  {
    size_t n = height.size();
    vector<int> left(n);
    vector<int> right(n);
    size_t i = 0, j = n - 1;
    int maxl = 0;
    int maxr = 0;
    while (i < n) {
      left[i] = maxl;
      right[j] = maxr;
      maxl = max(maxl, height[i]);
      maxr = max(maxr, height[j]);
      i++, j--;
    }

    int res = 0;
    for (i = 0; i < n; i++) {
      int water = min(left[i], right[i]);
      res += max(0, water - height[i]);
    }
    return res;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  vector v1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  vector v2 = {4, 2, 3};
  test(s.trap(v1) == 6);
  test(s.trap(v2) == 1);
  return 0;
}
