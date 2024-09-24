#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

// #pragma GCC optimize("O3") // comment this line while debugging
static const bool booster = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return true;
}();

class Solution {
  bool vowel(char c)
  {
    switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return true;
    default:
      return false;
    }
  }

public:
  int maxVowels(std::string s, int k)
  {
    int current = 0;
    for (int i = 0; i < k; i++)
      if (vowel(s[i])) current++;

    int max = current;
    for (int i = k; i < s.length(); i++) {
      if (vowel(s[i - k])) current--;
      if (vowel(s[i])) current++;

      if (max < current) max = current;
    }

    return max;
  }
};

int main()
{
  Solution s;
  std::cout << s.maxVowels("abciiidef", 3) << std::endl;
  return 0;
}