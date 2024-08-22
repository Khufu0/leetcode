#include <iostream>
#include <string>

class Solution {
public:
  std::string mergeAlternately(std::string word1, std::string word2)
  {
    std::string res;
    int i = 0;
    for (i = 0; i < word1.length(); i++) {
      res += word1[i];
      if (i < word2.length())
        res += word2[i];
    }
    if (i < word2.length())
      res.append(word2.substr(i));
    return res;
  }
};

int main()
{
  std::string s1 = "aceg";
  std::string t1 = "bdfh";
  std::string s2 = "aaa";
  std::string t2 = "bbbbbb";
  std::string s3 = "aaa";
  std::string t3 = "b";

  Solution s;

  std::cout << s.mergeAlternately(s1, t1) << std::endl;
  std::cout << s.mergeAlternately(s2, t2) << std::endl;
  std::cout << s.mergeAlternately(s3, t3) << std::endl;
  return 0;
}
