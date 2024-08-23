#include <iostream>

class Solution {
public:
  std::string toLowerCase(std::string s)
  {
    std::string res = std::move(s);
    for (char &c : res) {
      if (c < 91 && c > 64) {
        c += 32;
      }
    }
    return res;
  }
};

int main()
{
  std::string t1 = "Hello";
  std::string t2 = "here";
  std::string t3 = "LOV&LY";

  Solution s;

  std::cout << s.toLowerCase(t1) << std::endl;
  std::cout << s.toLowerCase(t2) << std::endl;
  std::cout << s.toLowerCase(t3) << std::endl;

  return 0;
}