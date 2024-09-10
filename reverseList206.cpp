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
  ListNode *reverseList(ListNode *head)
  {
    ListNode dum;
    ListNode *temp = nullptr;
    auto it = head;

    while (it != nullptr) {
      temp = dum.next;
      dum.next = it;
      it = it->next;
      dum.next->next = temp;
    }

    return dum.next;
  }
};

int main()
{
  ListNode *l1 = new ListNode{
      1, new ListNode{
             2, new ListNode{3, new ListNode{4, new ListNode{5, new ListNode{6}}}}}};

  Solution s;
  ListNode *x = s.reverseList(l1);

  for (ListNode *it = x; it != nullptr; it = it->next)
    std::cout << it->val << std::endl;

  return 0;
}
