#include <iostream>
#include <string>

class Solution {
  enum direction { n, e, s, w };

public:
  bool isRobotBounded(std::string instructions)
  {
    int d = n;
    int moves[4];
    for (auto c : instructions) {
      switch (c) {
      case 'G':
        moves[d]++;
        break;
      case 'L':
        d = (d + 1) % 4;
        break;
      case 'R':
        d = (d + 3) % 4;
        break;
      }
    }
    return (moves[n] == moves[s] && moves[e] == moves[w]) || d != n;
  }
};

// class Solution {
//   struct coordinates {
//     int x, y;
//   };

//   enum direction { n, e, s, w };

// public:
//   bool isRobotBounded(std::string instructions)
//   {
//     coordinates co{0, 0};
//     int d = n;
//     for (auto c : instructions) {
//       switch (c) {
//       case 'G':
//         switch (d) {
//         case n:
//           co.y += 1;
//           break;
//         case s:
//           co.y -= 1;
//           break;
//         case e:
//           co.x += 1;
//           break;
//         case w:
//           co.x -= 1;
//           break;
//         }
//         break;
//       case 'L':
//         d = (d + 1) % 4;
//         break;
//       case 'R':
//         d = (d + 3) % 4;
//         break;
//       }
//     }
//     return (co.x == 0 && co.y == 0) || d != n;
//   }
// };

int main()
{
  std::string t1 = "GGLLGG";
  std::string t2 = "GG";

  Solution s;
  std::cout << std::boolalpha;
  std::cout << s.isRobotBounded(t1) << std::endl;
  std::cout << s.isRobotBounded(t2) << std::endl;

  return 0;
}
