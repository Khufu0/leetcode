#include <iostream>
#include <vector>

class Solution {
public:
  int maximumWealth(std::vector<std::vector<int>> &accounts)
  {
    int wealth = 0;
    for (int i = 0; i < accounts.size(); i++) {
      int x = 0;
      for (int j = 0; j < accounts.at(i).size(); j++) {
        x += accounts.at(i).at(j);
      }
      if (x > wealth)
        wealth = x;
      x = 0;
    }
    return wealth;
  }
};

int main()
{
  std::vector<std::vector<int>> t1 = {{1, 2, 3}, {3, 2, 1}};
  std::vector<std::vector<int>> t2 = {{1, 5}, {7, 3}, {3, 5}};

  Solution s;
  std::cout << s.maximumWealth(t1) << std::endl;
  std::cout << s.maximumWealth(t2) << std::endl;
}