#include <algorithm>
#include <array>
#include <iostream>
#include <string>

class Solution {
public:
  // bool isAnagram(std::string s, std::string t)
  // {
  //   if (s.length() != t.length())
  //     return false;

  //   std::sort(s.begin(), s.end());
  //   std::sort(t.begin(), t.end());

  //   return s == t;
  // }

  bool isAnagram(std::string s, std::string t)
  {
    if (s.length() != t.length())
      return false;

    std::array<int, 26> frequency;

    for (auto c : s)
      frequency[c - 'a']++;

    for (auto c : t)
      frequency[c - 'a']--;

    for (auto i : frequency)
      if (i != 0)
        return false;

    return true;
  }
};

int main()
{
  std::string s1 = "anagram";
  std::string t1 = "nagaram";
  std::string s2 = "rat";
  std::string t2 = "car";

  Solution s;

  std::cout << s.isAnagram(s1, t1) << std::endl;
  std::cout << s.isAnagram(s2, t2) << std::endl;
  return 0;
}