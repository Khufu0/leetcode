#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
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

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr)
  {
  }

  ListNode(int x) : val(x), next(nullptr)
  {
  }

  ListNode(int x, ListNode *next) : val(x), next(next)
  {
  }
};

class Solution {
public:
  ListNode *middleNode(ListNode *head)
  {
    ListNode *s, *f;
    s = f = head;
    while (f && f->next) {
      s = s->next;
      f = f->next->next;
    }
    return s;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
