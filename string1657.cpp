#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string, std::vector, std::numeric_limits;

template <typename... T>
void pln(T... args)
{
  (std::cout << ... << args) << "\n";
}

void test(bool cond)
{
  if (cond) pln("Passed!!");
  else pln("Failed!!");
}

//----------------------------------------------------------------------------------
// #pragma GCC optimize("O3") // comment this line while debugging
namespace {
static const bool __booster = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return true;
}();
} // namespace

class Solution {
public:
  bool closeStrings(string word1, string word2)
  {
    size_t n1 = word1.size();
    size_t n2 = word2.size();
    if (n1 != n2) return false;

    std::array<int, 26> freq1;
    std::array<int, 26> freq2;
    std::set<int> s1;
    std::set<int> s2;

    for (size_t i = 0; i < n1; i++) {
      freq1[word1[i] - 'a']++;
      freq2[word2[i] - 'a']++;
      s1.insert(word1[i]);
      s2.insert(word2[i]);
    }

    std::sort(freq1.begin(), freq1.end());
    std::sort(freq2.begin(), freq2.end());

    if (freq1 == freq2 && s1 == s2) return true;
    return false;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  test(s.closeStrings("abc", "bca") == true);
  test(s.closeStrings("a", "aa") == false);
  test(s.closeStrings("cabbba", "abbccc") == false);
  return 0;
}
