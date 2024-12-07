#include <bits/stdc++.h>
using namespace std;

template <typename... T>
void pln(T... args)
{
  (cout << ... << args) << '\n';
}

void test(bool cond)
{
  if (cond) pln("Passed!!");
  else pln("Failed!!");
}

//----------------------------------------------------------------------------------
namespace {
static const bool __booster = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return true;
}();
} // namespace

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int x) : val(x), next(NULL)
  {
  }
};

class Solution {
public:
  bool hasCycle(ListNode *head)
  {
    ListNode *f{head}, *s{head};
    while (f && f->next) {
      s = s->next;
      f = f->next->next;
      if (s == f) return true;
    }
    return false;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}

// class Solution {
// public:
//   bool hasCycle(ListNode *head)
//   {
//     unordered_set<ListNode *> visited;
//     while (head) {
//       if (visited.contains(head)) return true;
//       visited.emplace(head);
//       head = head->next;
//     }
//     return false;
//   }
// };