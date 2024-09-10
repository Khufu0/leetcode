#include <iostream>
#include <string>

class Solution {
public:
  std::string addBinary(std::string a, std::string b)
  {
    // a is always bigger
    if (a.length() < b.length())
      std::swap(a, b);

    bool carry = false;

    int ai = a.length() - 1;
    int bi = b.length() - 1;

    for (; bi >= 0; ai--, bi--) {
      if (b[bi] == '1' && a[ai] == '1') {
        a[ai] = '0';
        carry = true;
        for (int j = ai - 1; j >= 0; j--) {
          if (a[j] == '0') {
            a[j] = '1';
            carry = false;
            break;
          }
          else {
            a[j] = '0';
          }
        }
        if (carry) {
          a.insert(a.begin(), '1');
          ai++;
          carry = false;
        }
      }
      else if (b[bi] == '1' && a[ai] == '0') {
        a[ai] = '1';
      }
    }
    return a;
  }
};

int main()
{
  std::string t11 = "11";
  std::string t12 = "11111111111111";
  std::string t21 = "1010";
  std::string t22 = "1011";
  std::string t31 = "1111";
  std::string t32 = "111111111";

  Solution s;
  std::cout << s.addBinary(t11, t12) << std::endl;
  std::cout << s.addBinary(t21, t22) << std::endl;
  std::cout << s.addBinary(t31, t32) << std::endl;

  return 0;
}