#include <iostream>
#include <vector>

class Solution {
public:
  bool isMonotonic(std::vector<int> &nums)
  {
    int i = 0;
    for (; i < nums.size() - 1; i++) // inc
      if (nums[i] > nums[i + 1])
        break;

    if (i + 1 == nums.size())
      return true;

    for (i = 0; i < nums.size() - 1; i++) // dec
      if (nums[i] < nums[i + 1])
        return false;

    return true;
  }
};

int main()
{
  std::vector v1 = {1, 2, 2, 3};
  std::vector v2 = {1, 3, 2};

  Solution s;
  std::cout << std::boolalpha;
  std::cout << s.isMonotonic(v1) << std::endl;
  std::cout << s.isMonotonic(v2) << std::endl;

  return 0;
}