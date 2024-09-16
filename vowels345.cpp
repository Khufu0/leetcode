#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// fun fact: i wrote both solutions using my brain!.
class Solution {
  bool vowel(char c)
  {
    switch (c) {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
      return true;
    default:
      return false;
    }
  }

public:
  std::string reverseVowels(std::string s)
  {
    int i = 0, j = s.length() - 1;
    while (i < j) {
      if (vowel(s[i]) && vowel(s[j])) {
        std::swap(s[i], s[j]);
        i++, j--;
      }
      else if (!vowel(s[i])) i++;
      else j--;
    }
    return s;
  }

  //   std::string reverseVowels(std::string s)
  //   {
  //     std::vector<int> vowels;
  //     std::string res;
  //     for (size_t i = 0; i < s.length(); i++) {
  //       if (vowel(s[i])) vowels.push_back(i);
  //     }
  //     size_t j = vowels.size() - 1;
  //     for (size_t i = 0; i < s.length(); i++) {
  //       if (std::binary_search(vowels.begin(), vowels.end(), i)) {
  //         res += s[vowels[j]];
  //         j--;
  //       }
  //       else res += s[i];
  //     }
  //     return res;
  //   }
};

int main()
{
  std::string str1 = "IceCreAm";
  std::string str2 = "ai";
  Solution s;
  std::cout << s.reverseVowels(str1) << std::endl;
  std::cout << s.reverseVowels(str2) << std::endl;
  return 0;
}
