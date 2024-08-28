#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int countOdds(int low, int high)
  {
    return (low % 2 != 0 || high % 2 != 0) ? (high - low) / 2 + 1 : (high - low) / 2;
  }
};

int main()
{
  int t1_1 = 0;
  int t1_2 = 10;
  int t2_1 = 3;
  int t2_2 = 7;

  Solution s;
  std::cout << s.countOdds(t1_1, t1_2) << std::endl;
  std::cout << s.countOdds(t2_1, t2_2) << std::endl;

  return 0;
}