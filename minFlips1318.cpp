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
public:
  int minFlips(int a, int b, int c)
  {
    int cnt = 0;
    for (int i = 0; i < sizeof(int) * 8; i++) {
      int s = 1 << i;
      if ((s & c) == ((s & a) | (s & b))) {
        continue;
      }
      else {
        if (s & c) cnt++;
        else {
          if (s & a) cnt++;
          if (s & b) cnt++;
        }
      }
    }
    return cnt;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
