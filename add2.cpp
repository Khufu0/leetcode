#include <algorithm>
#include <climits>
#include <cstdint>
#include <functional>
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode dum;
    ListNode *tail = &dum;
    int sum = 0;
    int carry = 0;

    while (l1 || l2 || carry > 0) {
      sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = sum / 10;
      tail->next = new ListNode(sum % 10);
      tail = tail->next;
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
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

  //[1000000000000000000000000000001]
  ListNode *l21 = new ListNode{
      1,
      new ListNode{
          0,
          new ListNode{
              0,
              new ListNode{
                  0,
                  new ListNode{
                      0,
                      new ListNode{
                          0,
                          new ListNode{
                              0,
                              new ListNode{
                                  0,
                                  new ListNode{
                                      0,
                                      new ListNode{
                                          0,
                                          new ListNode{
                                              0,
                                              new ListNode{
                                                  0,
                                                  new ListNode{
                                                      0,
                                                      new ListNode{
                                                          0,
                                                          new ListNode{
                                                              0,
                                                              new ListNode{
                                                                  0,
                                                                  new ListNode{
                                                                      0,
                                                                      new ListNode{
                                                                          0,
                                                                          new ListNode{
                                                                              0,
                                                                              new ListNode{
                                                                                  0,
                                                                                  new ListNode{
                                                                                      0,
                                                                                      new ListNode{
                                                                                          0,
                                                                                          new ListNode{
                                                                                              0,
                                                                                              new ListNode{
                                                                                                  0,
                                                                                                  new ListNode{
                                                                                                      0,
                                                                                                      new ListNode{
                                                                                                          0,
                                                                                                          new ListNode{
                                                                                                              0,
                                                                                                              new ListNode{
                                                                                                                  0,
                                                                                                                  new ListNode{
                                                                                                                      0,
                                                                                                                      new ListNode{
                                                                                                                          0,
                                                                                                                          new ListNode{
                                                                                                                              1}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}};
  ListNode *l22 = new ListNode{5, new ListNode{6, new ListNode{4}}};

  Solution s;
  ListNode *x1 = s.addTwoNumbers(l11, l12);
  ListNode *x2 = s.addTwoNumbers(l21, l22);

  for (ListNode *it = x1; it != nullptr; it = it->next)
    std::cout << it->val << " ";

  std::cout << std::endl
            << "*********************************************************"
            << std::endl;

  for (ListNode *it = x2; it != nullptr; it = it->next)
    std::cout << it->val << " ";

  std::cout << std::endl;

  return 69 ^ 69;
}
// A fuck around algo
//   ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
//   {
//     std::function<uint64_t(ListNode * l, uint64_t d)> get_num;
//     uint64_t d1 = 1, d2 = 1;
//     get_num = [&](ListNode *l, uint64_t d) {
//       if (l->next == nullptr) return uint64_t(l->val) * d;
//       else [[likely]] return uint64_t(l->val) * d + get_num(l->next, d * 10);
//     };
//     uint64_t n1 = get_num(l1, d1);
//     uint64_t n2 = get_num(l2, d2);

//     uint64_t sum = n1 + n2;
//     if (sum == 0) return new ListNode{0};

//     ListNode dum;
//     ListNode *tail = &dum;

//     while (sum > 0) {
//       tail->next = new ListNode(sum % 10);
//       sum /= 10;
//       tail = tail->next;
//     }
//     return dum.next;
//   }