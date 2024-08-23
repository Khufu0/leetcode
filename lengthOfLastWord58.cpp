#include <iostream>

class Solution {
public:
  int lengthOfLastWord(std::string w)
  {
    int i = w.size() - 1;
    if (w.ends_with(" "))
      i = w.find_last_not_of(" ");
    int len = 0;
    while (i >= 0 && w[i] != ' ') {
      len++;
      i--;
    }
    return len;
  }
};

int main()
{
  std::string t1 = "Hello World";
  std::string t2 = "   fly me   to   the moon  ";
  std::string t3 = "a";
  std::string t4 = "a ";
  std::string t5 = "nour";

  Solution s;

  std::cout << s.lengthOfLastWord(t1) << std::endl;
  std::cout << s.lengthOfLastWord(t2) << std::endl;
  std::cout << s.lengthOfLastWord(t3) << std::endl;
  std::cout << s.lengthOfLastWord(t4) << std::endl;
  std::cout << s.lengthOfLastWord(t5) << std::endl;

  return 0;
}
