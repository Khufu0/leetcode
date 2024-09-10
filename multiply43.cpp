#include <algorithm>
#include <iostream>
#include <string>

#define CTOI(x) int(x - '0')
#define ITOC(x) int(x + '0')

class Solution {
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

public:
  std::string multiply(std::string num1, std::string num2)
  {
    if (num1 == "0" || num2 == "0") return "0";
    if (num1.length() < num2.length()) std::swap(num1, num2);

    std::string res;
    std::string curr;
    int zeros = 1;
    int carry = 0;
    int i1 = num1.length() - 1;
    int i2 = num2.length() - 1;

    for (; i2 >= 0; i2--) {
      for (; i1 >= 0; i1--) {
        int x = CTOI(num1[i1]) * CTOI(num2[i2]) + carry;
        carry = x / 10;
        curr.insert(curr.begin(), ITOC(x % 10));
      }
      if (carry) {
        curr.insert(curr.begin(), ITOC(carry));
      }
      res = addStrings(res, curr);
      i1 = num1.length() - 1;
      curr.clear();
      curr.append(zeros++, '0');
      carry = 0;
    }
    std::reverse(res.begin(), res.end());

    return res;
  }
};

int main()
{
  std::string t11 = "4293350023709564911274151143";
  std::string t12 = "1355211911260486027259100933586";
  std::string t21 = "9133";
  std::string t22 = "0";
  std::string t31 = "69";
  std::string t32 = "6969";

  Solution s;
  std::cout << s.multiply(t11, t12) << std::endl;
  std::cout << s.multiply(t21, t22) << std::endl;
  std::cout << s.multiply(t31, t32) << std::endl;

  return 0;
}