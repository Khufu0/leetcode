#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits)
  {
    std::vector<int> res = digits;
    bool one = false;
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] == 9) {
        one = true;
        res[i] = 0;
      }
      else {
        res[i] = digits[i] + 1;
        one = false;
        break;
      }
    }
    if (one)
      res.insert(res.begin(), 1);
    return res;
  }
};

int main()
{
  std::vector n1 = {4, 0, 0};
  std::vector n2 = {3, 9, 9};
  std::vector n3 = {9, 9, 9};

  Solution s;
  n1 = s.plusOne(n1);
  n2 = s.plusOne(n2);
  n3 = s.plusOne(n3);

  for (auto i : n1) {
    std::cout << i;
  }
  std::cout << std::endl;

  for (auto i : n2) {
    std::cout << i;
  }
  std::cout << std::endl;

  for (auto i : n3) {
    std::cout << i;
  }
  std::cout << std::endl;

  return 0;
}
