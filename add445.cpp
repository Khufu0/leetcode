#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stack>

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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode dum;
    ListNode *temp = nullptr;
    int sum = 0;
    int carry = 0;
    std::stack<int> s1;
    std::stack<int> s2;

    while (l1 || l2) {
      if (l1) {
        s1.push(l1->val);
        l1 = l1->next;
      }
      if (l2) {
        s2.push(l2->val);
        l2 = l2->next;
      }
    }

    while (!s1.empty() || !s2.empty() || carry > 0) {
      sum = carry;
      if (!s1.empty()) {
        sum += s1.top();
        s1.pop();
      }
      if (!s2.empty()) {
        sum += s2.top();
        s2.pop();
      }
      carry = sum / 10;
      temp = dum.next;
      dum.next = new ListNode(sum % 10);
      dum.next->next = temp;
    }

    return dum.next;
  }
};

int main()
{
  ListNode *l11 = new ListNode{
      9, new ListNode{
             9, new ListNode{
                    9, new ListNode{
                           9, new ListNode{9, new ListNode{9, new ListNode{9}}}}}}};
  ListNode *l12 = new ListNode{9, new ListNode{9, new ListNode{9, new ListNode{9}}}};

  Solution s;
  ListNode *x1 = s.addTwoNumbers(l11, l12); // 10009998

  for (ListNode *it = x1; it != nullptr; it = it->next)
    std::cout << it->val << " ";

  std::cout << std::endl;

  return 69 ^ 69;
}
