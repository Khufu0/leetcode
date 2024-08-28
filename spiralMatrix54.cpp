#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
  {
    std::vector<int> res;
    int l = 0;
    int r = matrix[0].size();
    int t = 0;
    int b = matrix.size();
    while (res.size() != matrix.size() * matrix[0].size()) {
      // top
      for (int i = l; i < r; i++)
        res.push_back(matrix[t][i]);
      t++;
      // right
      for (int i = t; i < b; i++)
        res.push_back(matrix[i][r - 1]);
      r--;
      if (res.size() == matrix.size() * matrix[0].size())
        break;
      // bottom
      for (int i = r - 1; i >= l; i--)
        res.push_back(matrix[b - 1][i]);
      b--;
      // left
      for (int i = b - 1; i >= t; i--)
        res.push_back(matrix[i][l]);
      l++;
    }
    return res;
  }
};

int main()
{
  std::vector<std::vector<int>> t1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  std::vector<std::vector<int>> t2 = {{7}, {9}, {6}};
  Solution s;
  for (auto i : s.spiralOrder(t1))
    std::cout << i << " ";
  std::cout << std::endl;
  for (auto i : s.spiralOrder(t2))
    std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}