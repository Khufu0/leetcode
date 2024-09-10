#include <iostream>

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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode dum;
    ListNode *tail = &dum;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      }
      else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }
    if (l1) tail->next = l1;
    else if (l2) tail->next = l2;

    return dum.next;
  }
};

int main()
{
  ListNode *l1 = new ListNode{1, new ListNode{3, new ListNode{5}}};
  ListNode *l2 = new ListNode{1, new ListNode{2, new ListNode{6}}};

  Solution s;
  ListNode *x = s.mergeTwoLists(l1, l2);

  for (ListNode *it = x; it != nullptr; it = it->next)
    std::cout << it->val << std::endl;

  return 0;
}
