#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  bool lemonadeChange(std::vector<int> &b)
  {
    int five = 0;
    int ten = 0;
    int debt = 0;
    for (int bill : b) {
      switch (bill) {
      case 5:
        five++;
        break;
      case 10:
        if (five) {
          five--;
        }
        else {
          debt += 5;
        }
        ten++;
        break;
      case 20:
        int rest = 15;
        if (ten) {
          ten--;
          rest -= 10;
          if (five) {
            five--;
            rest -= 5;
          }
        }
        else {
          for (int i = 0; i < 3; i++) {
            if (five) {
              five--;
              rest -= 5;
            }
            else {
              break;
            }
          }
        }
        if (rest) {
          debt += rest;
        }
        break;
      }
    }
    return debt == 0;
  }
};

int main()
{
  std::vector<int> t1 = {5, 5, 5, 10, 20};
  std::vector<int> t2 = {5, 5, 10, 20, 5, 5, 5,  5, 5,  5,
                         5, 5, 5,  10, 5, 5, 20, 5, 20, 5};
  Solution s;
  std::cout << std::boolalpha;
  std::cout << s.lemonadeChange(t1) << std::endl;
  std::cout << s.lemonadeChange(t2) << std::endl;
  return 0;
}