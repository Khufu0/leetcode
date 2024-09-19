#include <algorithm>
#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <vector>

#pragma GCC optimize("O3")
static const bool booster = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return true;
}();

class Solution {
public:
  bool isSubsequence(std::string s, std::string t)
  {
    size_t i2 = 0;
    for (size_t i = 0; i < t.length(); i++) {
      if (t[i] == s[i2]) {
        i2++;
        if (i2 == s.length()) return true;
      }
    }
    return i2 == s.length();
  }
};

int main()
{
  Solution s;
  std::cout << std::boolalpha;
  std::cout << s.isSubsequence("abc", "ahbgdc") << std::endl;
  std::cout << s.isSubsequence("axc", "ahbgdc") << std::endl;
  return 0;
}