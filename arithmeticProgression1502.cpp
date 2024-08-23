#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  bool canMakeArithmeticProgression(std::vector<int> &arr)
  {
    std::sort(arr.begin(), arr.end());

    int diff = arr[0] - arr[1];
    for (int i = 1; i < arr.size() - 1; i++) {
      if (arr[i] - arr[i + 1] != diff)
        return false;
    }
    return true;
  }
};

int main()
{
  std::vector v1 = {3, 5, 1};
  std::vector v2 = {1, 2, 4};

  Solution s;
  std::cout << std::boolalpha;
  std::cout << s.canMakeArithmeticProgression(v1) << std::endl;
  std::cout << s.canMakeArithmeticProgression(v2) << std::endl;

  return 0;
}