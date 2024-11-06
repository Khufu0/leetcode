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
  vector<vector<string>> res;

  bool palindrome(const string &s, int l, int r)
  {
    while (l < r) {
      if (s[l] != s[r]) return false;
      l++, r--;
    }
    return true;
  }

  void backtrack(const string &s, vector<string> &part, int i = 0)
  {
    if (i == s.size()) {
      res.emplace_back(part.begin(), part.end());
      return;
    }
    for (int j = i; j < s.size(); j++) {
      if (palindrome(s, i, j)) {
        part.emplace_back(s.substr(i, j + 1));
        backtrack(s, part, j + 1);
        part.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s)
  {
    vector<string> part;
    backtrack(s, part);
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
