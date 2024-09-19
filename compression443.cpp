#include <algorithm>
#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <vector>

// #pragma GCC optimize("O3")
static const bool booster = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return true;
}();

class Solution {
public:
  int compress(std::vector<char> &chars)
  {
    size_t n = chars.size();
    if (n == 1) return 1;

    std::string compressed;

    int freq = 0;
    size_t i = 0, j = i;
    while (i < n) {
      while (j < n) {
        if (chars[j] == chars[i]) freq++, j++;
        else break;
      }
      auto it = compressed.insert(compressed.end(), chars[i]) + 1;
      if (freq > 9) {
        while (freq > 9) {
          compressed.insert(it, freq % 10 + '0');
          freq /= 10;
        }
        compressed.insert(it, freq + '0');
      }
      else if (freq > 1) compressed.insert(it, freq + '0');
      i = j;
      freq = 0;
    }
    i = 0;
    for (; i < compressed.size(); i++) {
      chars[i] = compressed[i];
    }

    return compressed.size();
  }
};

int main()
{
  std::vector v1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  std::vector v2 = {'a'};
  std::vector v3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
  Solution s;
  std::cout << s.compress(v1) << std::endl;
  std::cout << s.compress(v2) << std::endl;
  std::cout << s.compress(v3) << std::endl;
  return 0;
}