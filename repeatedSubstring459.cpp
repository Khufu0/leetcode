#include <iostream>
#include <string>

class Solution {
public:
  bool repeatedSubstringPattern(std::string s)
  {
    for (int i = 1; i <= s.length() / 2; i++) {
      if (s.length() % i == 0) {
        int r = s.length() / i;
        std::string p;
        std::string t(s.substr(0, i));
        for (; r > 0; r--) {
          p += t;
        }
        if (s == p) {
          return true;
        }
      }
    }
    return false;
  }
};

int main()
{
  std::string s1 = "acacc";
  std::string s2 = "abab";
  std::string s3 = "aa";
  std::string s4 = "bbbbbb";

  Solution s;

  std::cout << std::boolalpha;
  std::cout << s.repeatedSubstringPattern(s1) << std::endl;
  std::cout << s.repeatedSubstringPattern(s2) << std::endl;
  std::cout << s.repeatedSubstringPattern(s3) << std::endl;
  std::cout << s.repeatedSubstringPattern(s4) << std::endl;
  return 0;
}
