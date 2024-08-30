#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  bool checkStraightLine(std::vector<std::vector<int>> &coordinates)
  {
    if (coordinates.size() == 2)
      return true;
    int x1 = coordinates[0][0];
    int y1 = coordinates[0][1];
    int x2 = coordinates[1][0];
    int y2 = coordinates[1][1];
    for (int i = 2; i < coordinates.size(); i++) {
      if (((coordinates[i][1] - y1) * (x2 - x1)) !=
          ((y2 - y1) * (coordinates[i][0] - x1))) {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  std::vector<std::vector<int>> t1 = {{1, 2}, {2, 3}, {3, 4},
                                      {4, 5}, {5, 6}, {6, 7}};
  std::vector<std::vector<int>> t2 = {{1, 1}, {2, 2}, {3, 4},
                                      {4, 5}, {5, 6}, {7, 7}};
  std::vector<std::vector<int>> t3 = {{0, 0}, {0, 5}, {5, 0}, {1337, 0}, {0, 1337}};
  std::vector<std::vector<int>> t4 = {{0, 0}, {0, 5}, {5, 5}, {5, 0}};

  Solution s;
  std::cout << std::boolalpha;
  std::cout << s.checkStraightLine(t1) << std::endl;
  std::cout << s.checkStraightLine(t2) << std::endl;
  std::cout << s.checkStraightLine(t3) << std::endl;
  std::cout << s.checkStraightLine(t4) << std::endl;
  return 0;
}