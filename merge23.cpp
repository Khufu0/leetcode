#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
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
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    struct greater {
      constexpr bool operator()(const ListNode *x, const ListNode *y) const
      {
        return x->val > y->val;
      }
    };

    std::priority_queue<ListNode *, std::vector<ListNode *>, greater> pq;
    for (auto n : lists) {
      if (n) pq.push(n);
    }
    ListNode dum;
    ListNode *last = &dum;
    while (!pq.empty()) {
      last = last->next = pq.top();
      if (last->next) pq.push(last->next);
      pq.pop();
    }
    return dum.next;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  vector<ListNode *> v1(3);
  v1[0] = new ListNode(1, new ListNode(4, new ListNode(5)));
  v1[1] = new ListNode(1, new ListNode(3, new ListNode(4)));
  v1[2] = new ListNode(2, new ListNode(6));
  s.mergeKLists(v1);

  vector<ListNode *> v2(2);
  v2[0] = new ListNode(1);
  v2[1] = new ListNode(0);
  s.mergeKLists(v2);

  return 0;
}

//   ListNode *mergeKLists(vector<ListNode *> &lists)
//   {
//     if (lists.empty()) return nullptr;
//     else if (lists.size() == 1) return lists[0];

//     ListNode dum;
//     ListNode *last = &dum;
//     while (69) {
//       bool empty = true;
//       size_t min = 0;
//       for (size_t i = 0; i < lists.size(); i++) {
//         auto n = lists[i];
//         if (n != nullptr) empty = false;
//         else continue;
//         min = (lists[min] == nullptr || n->val < lists[min]->val) ? i : min;
//       }
//       if (empty) break;
//       last->next = lists[min];
//       lists[min] = lists[min]->next;
//       last = last->next;
//     }
//     return dum.next;
//   }