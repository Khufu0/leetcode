#include <cstring>
#include <iostream>
#include <string>
#include <vector>

class Solution {
  enum square { e, x, o };

  inline std::string winner(square s)
  {
    switch (s) {
    case x:
      return "A";
    case o:
      return "B";
    default:
      return "";
    }
  }

public:
  std::string tictactoe(std::vector<std::vector<int>> &moves)
  {
    std::vector grid(3, std::vector(3, e));
    for (auto i = 0; i != moves.size(); i++) {
      if (i % 2 != 0)
        grid[moves.at(i).at(0)][moves.at(i).at(1)] = o;
      else
        grid[moves.at(i).at(0)][moves.at(i).at(1)] = x;
    }

    // h
    for (auto i = 0; i != 3; i++) {
      if (grid[i][0] != e && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
        return winner(grid[i][2]);
    }
    // v
    for (auto i = 0; i != 3; i++) {
      if (grid[0][i] != e && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
        return winner(grid[2][i]);
    }
    // d
    if (grid[0][0] != e && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
      return winner(grid[2][2]);
    if (grid[2][0] != e && grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2])
      return winner(grid[0][2]);

    return moves.size() == 9 ? "Draw" : "Pending";
  }
};

int main()
{
  std::vector<std::vector<int>> t1 = {{0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2}};
  std::vector<std::vector<int>> t2 = {{0, 0}, {1, 1}, {2, 0}, {1, 0}, {1, 2},
                                      {2, 1}, {0, 1}, {0, 2}, {2, 2}};

  Solution s;
  std::cout << s.tictactoe(t1) << std::endl;
  std::cout << s.tictactoe(t2) << std::endl;

  return 0;
}
