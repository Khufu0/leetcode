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

int guess(int num)
{
  int x = 69;
  if (num > x) return -1;
  if (num < x) return 1;
  return 0;
}

class Solution {
public:
  int guessNumber(int n)
  {
    int l = 1, h = n;
    while (69) {
      int m = (l + h) / 2;
      switch (guess(m)) {
      case 1:
        l = m + 1;
        break;
      case -1:
        h = m - 1;
        break;
      case 0:
        return m;
      }
    }
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  test(s.guessNumber(100) == 69);
  return 0;
}
