#include <algorithm>
#include <iostream>
#include <vector>

// fuck leetcode descriptions

class Solution {
public:
  // void moveZeroes(std::vector<int> &nums)
  // {
  //   int zeros = 0;
  //   std::vector<int> res;
  //   for (int i = 0; i < nums.size(); i++) {
  //     if (nums[i] != 0) {
  //       res.push_back(nums[i]);
  //     }
  //     else {
  //       zeros++;
  //     }
  //   }
  //   for (; zeros > 0; zeros--) {
  //     res.push_back(0);
  //   }
  //   nums = std::move(res);
  // }

  // void moveZeroes(std::vector<int> &nums)
  // {
  //   int zerosIdx = 0;
  //   for (int i = 0; i < nums.size(); i++) {
  //     if (nums[i] != 0) {
  //       nums[zerosIdx++] = nums[i];
  //     }
  //   }
  //   for (; zerosIdx < nums.size(); zerosIdx++) {
  //     nums[zerosIdx] = 0;
  //   }
  // }

  void moveZeroes(std::vector<int> &nums)
  {
    // all nums at index that's <= non_zeros are non zeros values
    int non_zeros = -1;
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] != 0)
        std::swap(nums[++non_zeros], nums[i]);
  }
};

int main()
{
  std::vector v = {1, 0, 3, 0, 12};

  Solution s;
  s.moveZeroes(v);

  for (auto i : v) {
    std::cout << i << std::endl;
  }

  return 0;
}
