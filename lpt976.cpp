#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int largestPerimeter(std::vector<int> &nums)
  {
    std::sort(nums.begin(), nums.end());
    for (auto it = nums.rbegin(); it != std::prev(nums.rend(), 2); it++)
      if (*it < *std::next(it, 2) + *std::next(it))
        return *it + *std::next(it) + *std::next(it, 2);
    return 0;
  }
};

int main()
{
  std::vector<int> t1 = {1, 2, 3};
  std::vector<int> t2 = {1, 2, 1, 10};
  std::cout << *(t1.rend() - 1) << std::endl;
  std::cout << *(t1.rend() - 2) << std::endl;
  std::cout << *(t1.rend() - 3) << std::endl;
  Solution s;
  std::cout << s.largestPerimeter(t1) << std::endl;
  std::cout << s.largestPerimeter(t2) << std::endl;
  return 0;
}