#include <iostream>
#include <string>

class Solution {
  struct coordinates {
    int x, y;
  };

public:
  bool judgeCircle(std::string moves)
  {
    coordinates coor{0, 0};
    for (auto c : moves) {
      switch (c) {
      case 'U':
        coor.y += 1;
        break;
      case 'D':
        coor.y -= 1;
        break;
      case 'L':
        coor.x += 1;
        break;
      case 'R':
        coor.x -= 1;
        break;
      }
    }
    return coor.x == 0 && coor.y == 0;
  }
};

int main()
{
  std::string t1 = "UD";
  std::string t2 = "LL";

  Solution s;
  std::cout << std::boolalpha;
  std::cout << s.judgeCircle(t1) << std::endl;
  std::cout << s.judgeCircle(t2) << std::endl;

  return 0;
}
