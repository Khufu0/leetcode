#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#pragma GCC optimize("O3")
static const bool Booster = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return true;
}();

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums)
  {
    size_t n = nums.size();
    std::vector<int> res(n);
    int prefix = 1;
    int suffix = 1;

    for (int l = 0; l < n; l++) {
      res[l] = prefix;
      prefix *= nums[l];
    }

    for (int r = n - 1; r >= 0; r--) {
      res[r] *= suffix;
      suffix *= nums[r];
    }

    return res;
  }
};

int main()
{
  std::vector v1 = {1, 2, 3, 4};
  std::vector v2 = {-1, 1, 0, -3, 3};
  Solution s;
  for (auto i : s.productExceptSelf(v1))
    std::cout << i << " ";
  std::cout << std::endl;
  for (auto i : s.productExceptSelf(v2))
    std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}

/*
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        size_t n = nums.size();
        std::vector<int> res(n);
        std::vector<int> left_mul(n);
        std::vector<int> right_mul(n);

        left_mul[0] = 1;
        for (int l = 1; l < n; l++) {
            left_mul[l] = nums[l - 1] * left_mul[l - 1];
        }

        right_mul[n - 1] = 1;
        for (int r = n - 2; r >= 0; r--) {
            right_mul[r] = nums[r + 1] * right_mul[r + 1];
        }

        for (int i = 0; i < n; i++) {
            res[i] = left_mul[i] * right_mul[i];
        }

        return res;
    }
};
*/