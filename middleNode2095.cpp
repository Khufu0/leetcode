#include <algorithm>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
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

// Definition for singly-linked list.
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
  ListNode *deleteMiddle(ListNode *head)
  {
    if (head->next == nullptr) {
      delete head;
      return nullptr;
    }
    ListNode *slower = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slower = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    slower->next = slower->next->next;
    delete slow;
    return head;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  ListNode *l1 = new ListNode{1, new ListNode{2, new ListNode{3, new ListNode{4}}}};
  ListNode *l2 = new ListNode{1, new ListNode{2, new ListNode{4}}};
  test(s.deleteMiddle(l1) == l2);
  return 0;
}

//   ListNode *deleteMiddle(ListNode *head)
//   {
//     int n = 0;
//     for (ListNode *it = head; it != nullptr; it = it->next)
//       n++;
//     if (n == 1) {
//       delete head;
//       return nullptr;
//     }
//     ListNode *prev = nullptr;
//     ListNode *it = head;
//     n /= 2;
//     for (; n > 0; n--) {
//       prev = it;
//       it = it->next;
//     }
//     prev->next = it->next;
//     delete it;
//     return head;
//   }