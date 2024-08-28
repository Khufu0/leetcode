#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  void setZeroes(std::vector<std::vector<int>> &matrix)
  {
    std::vector<bool> column(matrix.size(), false);
    std::vector<bool> row(matrix.at(0).size(), false);
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix.at(0).size(); j++) {
        if (matrix[i][j] == 0) {
          column.at(i) = true;
          row.at(j) = true;
        }
      }
    }
    for (int i = 0; i < column.size(); i++) {
      for (int j = 0; j < row.size(); j++) {
        if (column[i] || row[j])
          matrix[i][j] = 0;
      }
    }
  }
};

int main()
{
  std::vector<std::vector<int>> t1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  std::vector<std::vector<int>> t2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  Solution s;
  s.setZeroes(t1);
  s.setZeroes(t2);
  for (auto c : t1)
    for (auto i : c)
      std::cout << i << " ";
  std::cout << std::endl;
  for (auto c : t2)
    for (auto i : c)
      std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}