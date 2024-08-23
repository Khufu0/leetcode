#include <iostream>
#include <vector>

class Solution {
public:
  int arraySign(std::vector<int> &nums)
  {
    int negative_count = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0)
        return 0;
      if (nums[i] < 0)
        negative_count++;
    }
    return negative_count % 2 == 0 ? 1 : -1;
  }
};

int main()
{
  std::vector v = {-1, -2, -3, -4, 3, 2, 1};

  Solution s;
  std::cout << s.arraySign(v) << std::endl;

  return 0;
}