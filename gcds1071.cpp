#include <cstddef>
#include <iostream>
#include <string>

class Solution {
  constexpr std::string repeat(std::string sub, size_t times)
  {
    std::string res;
    for (; times > 0; times--) {
      res += sub;
    }
    return res;
  }

public:
  std::string gcdOfStrings(std::string str1, std::string str2)
  {
    if (str1 + str2 == str2 + str1) {
      size_t l1 = str1.length();
      size_t l2 = str2.length();
      size_t i = std::min(l1, l2);

      while (i > 0) {
        if (l1 % i == 0 && l2 % i == 0 &&
            repeat(str1.substr(0, i), l1 / i) == str1 &&
            repeat(str1.substr(0, i), l2 / i) == str2) {
          return str2.substr(0, i);
        }
        --i;
      }
    }
    return {};
  }
};

int main()
{
  std::string a = "ABABAB", b = "AB";
  Solution s;
  std::cout << s.gcdOfStrings(a, b) << std::endl;
  return 0;
}
