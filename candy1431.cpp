#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<bool> kidsWithCandies(std::vector<int> &candies, int extraCandies)
  {
    std::vector<bool> res;
    int max = *std::max_element(candies.begin(), candies.end());
    for (auto k : candies) {
      if (k + extraCandies >= max) res.push_back(true);
      else res.push_back(false);
    }
    return res;
  }
};

int main()
{
  std::vector<int> kids = {4, 2, 1, 1, 2};
  int extra = 1;
  Solution s;
  std::cout << std::boolalpha;
  for (auto k : s.kidsWithCandies(kids, extra))
    std::cout << k << std::endl;
  return 0;
}
