#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
  {
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    std::sort(nums1.begin(), nums1.end());
    if (nums1.size() % 2 != 0) {
      return nums1.at(nums1.size() / 2);
    }
    else {
      return ((nums1.at(nums1.size() / 2)) + (nums1.at((nums1.size() / 2) - 1))) /
             2.0;
    }
  }
};

int main()
{
  // 2
  std::vector t11 = {1, 3};
  std::vector t12 = {2};
  // 2.5
  std::vector t21 = {1, 2};
  std::vector t22 = {3, 4};

  Solution s;
  std::cout << s.findMedianSortedArrays(t11, t12) << std::endl;
  std::cout << s.findMedianSortedArrays(t21, t22) << std::endl;

  return 69 ^ 69;
}