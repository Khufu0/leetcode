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
  vector<string> res;

  string letters(char c)
  {
    static unordered_map<char, string> digitToLetters = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    return digitToLetters[c];
  }

  void backtrack(const string &digits, size_t i = 0, string current = "")
  {
    if (current.length() == digits.length()) {
      res.emplace_back(current);
      return;
    }
    for (char c : letters(digits[i])) {
      backtrack(digits, i + 1, current + c);
    }
  }

public:
  vector<string> letterCombinations(string digits)
  {
    if (digits.empty()) return res;
    backtrack(digits);
    return res;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  for (auto x : s.letterCombinations("9999"))
    std::cout << x << '\n';
  return 0;
}
