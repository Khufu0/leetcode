
#include <algorithm>
#include <iostream>
#include <string>

#define CTOI(x) x - '0'
#define ITOC(x) x + '0'

class Solution {
public:
  std::string addStrings(std::string num1, std::string num2)
  {
    int carry = 0;
    int i1 = num1.length() - 1;
    int i2 = num2.length() - 1;
    std::string res;

    while (i1 >= 0 || i2 >= 0 || carry) {
      int x = carry;
      if (i1 >= 0) {
        x += CTOI(num1[i1]);
        i1--;
      }
      if (i2 >= 0) {
        x += CTOI(num2[i2]);
        i2--;
      }
      carry = x / 10;
      res.push_back(ITOC(x % 10));
    }
    std::reverse(res.begin(), res.end());

    return res;
  }
};

int main()
{
  std::string t11 = "3";
  std::string t12 = "3";
  std::string t21 = "9";
  std::string t22 = "10";
  std::string t31 = "69";
  std::string t32 = "6969";

  Solution s;
  std::cout << s.addStrings(t11, t12) << std::endl;
  std::cout << s.addStrings(t21, t22) << std::endl;
  std::cout << s.addStrings(t31, t32) << std::endl;

  return 0;
}

// class Solution {
// public:
//   std::string addStrings(std::string num1, std::string num2)
//   {
//     if (num1.length() < num2.length()) std::swap(num1, num2);

//     int carry = 0;
//     int i1 = num1.length() - 1;
//     int i2 = num2.length() - 1;
//     std::string res;

//     for (int x; i1 >= 0; i1--, i2--) {
//       x = CTOI(num1[i1]) + (i2 >= 0 ? CTOI(num2[i2]) : 0) + carry;
//       carry = x / 10;
//       res.insert(res.begin(), ITOC(x % 10));
//     }

//     if (carry) res.insert(res.begin(), ITOC(carry));

//     return res;
//   }
// };