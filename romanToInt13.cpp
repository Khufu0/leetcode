#include <iostream>

// beats 100%
class Solution {
public:
  int romanToInt(std::string s)
  {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      switch (s[i]) {
      case 'I':
        if (i + 1 != s.size()) {
          if (s[i + 1] == 'V') {
            res += 4;
            i++;
            break;
          }
          else if (s[i + 1] == 'X') {
            res += 9;
            i++;
            break;
          }
        }
        res += 1;
        break;
      case 'V':
        res += 5;
        break;
      case 'X':
        if (i + 1 != s.size()) {
          if (s[i + 1] == 'L') {
            res += 40;
            i++;
            break;
          }
          else if (s[i + 1] == 'C') {
            res += 90;
            i++;
            break;
          }
        }
        res += 10;
        break;
      case 'L':
        res += 50;
        break;
      case 'C':
        if (i + 1 != s.size()) {
          if (s[i + 1] == 'D') {
            res += 400;
            i++;
            break;
          }
          else if (s[i + 1] == 'M') {
            res += 900;
            i++;
            break;
          }
        }
        res += 100;
        break;
      case 'D':
        res += 500;
        break;
      case 'M':
        res += 1000;
        break;
      }
    }
    return res;
  }
};

int main()
{
  std::string s1 = "III";
  std::string s2 = "LVIII";
  std::string s3 = "MCMXCIV";

  Solution s;
  std::cout << s.romanToInt(s1) << std::endl;
  std::cout << s.romanToInt(s2) << std::endl;
  std::cout << s.romanToInt(s3) << std::endl;

  return 0;
}