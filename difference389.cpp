#include <cstdlib>
#include <iostream>
#include <string>

class Solution {
public:
  char findTheDifference(std::string s, std::string t)
  {
    if (s.empty())
      return t.at(0);

    int sum_s = 0;
    int sum_t = 0;

    for (size_t i = 0; i < s.size(); i++) {
      sum_s += s.at(i);
      sum_t += t.at(i);
    }
    sum_t += t.at(s.size());

    return static_cast<char>(sum_t - sum_s);
  }
};

// class Solution {
// public:
//   char findTheDifference(std::string s, std::string t)
//   {
//     for (size_t i = 0; i < s.size(); i++)
//       t[i + 1] += t[i] - s[i];
//     return t.back();
//   }
// };

int main()
{
  std::string s1 = "iybsa";
  std::string t1 = "asisyb";

  std::string s2 = "";
  std::string t2 = "b";

  Solution solution;
  std::cout << solution.findTheDifference(s1, t1) << std::endl;
  std::cout << solution.findTheDifference(s2, t2) << std::endl;

  return 0;
}