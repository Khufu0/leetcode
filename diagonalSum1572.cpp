#include <iostream>
#include <vector>

class Solution {
public:
  int diagonalSum(std::vector<std::vector<int>> &mat)
  {
    int sum = 0;
    for (int i = 0, j = mat.size() - 1; i < mat.size(); i++, j--)
      if (i != j) [[likely]]
        sum = sum + mat.at(i).at(i) + mat.at(i).at(j);
      else
        sum += mat.at(i).at(i);
    return sum;
  }
};

int main()
{
  std::vector<std::vector<int>> t1 = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
  Solution s;
  std::cout << s.diagonalSum(t1) << std::endl;
  return 0;
}