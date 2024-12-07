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
  bool palindrome(const string &s, int l, int r)
  {
    while (l < r) {
      if (s[l] == s[r]) l++, r--;
      else return false;
    }
    return true;
  }

public:
  string longestPalindrome(string s)
  {
    int n = s.length();
    int ml = 0, mr = 0;
    for (int i = 0; i < n; i++) {
      int l = i, r = n - 1;
      if (mr - ml >= r - l) break;
      while (l <= r) {
        if (mr - ml >= r - l) break;
        if (palindrome(s, l, r)) {
          ml = l;
          mr = r;
          break;
        }
        else {
          r--;
        }
      }
    }
    return s.substr(ml, mr - ml + 1);
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  test(s.longestPalindrome("ac") == "a");
  test(s.longestPalindrome("cbbd") == "bb");
  return 0;
}
