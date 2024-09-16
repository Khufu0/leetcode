#include <iostream>
#include <vector>

class Solution {
public:
  bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
  {
    for (size_t i = 0; i < flowerbed.size(); i++) {
      bool left = i == 0 || flowerbed[i - 1] == 0;
      bool right = i == flowerbed.size() - 1 || flowerbed[i + 1] == 0;
      if (left && right && flowerbed[i] == 0) {
        flowerbed[i] = 1;
        n--;
      }
    }
    return n <= 0;
  }
};

int main()
{
  std::vector<int> flowerbed = {1, 0, 0, 0, 1};
  int n = 1;
  Solution s;
  std::cout << std::boolalpha << s.canPlaceFlowers(flowerbed, n) << std::endl;
  return 0;
}
