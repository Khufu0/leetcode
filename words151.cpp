#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#define ADVANCE_UNTILL(it, pred)                                                    \
  while (!(pred))                                                                   \
    it++;

class Solution {
public:
  std::string reverseWords(std::string s)
  {
    std::string res;
    std::stack<std::string> stack;
    auto b = s.begin(), e = s.begin();

    while (b != s.end()) {
      if (*b != ' ') {
        e = b;
        ADVANCE_UNTILL(e, *e == ' ' || e == s.end());
        stack.push({b, e});
        ADVANCE_UNTILL(b, *b == ' ' || b == s.end());
      }
      else b++;
    }

    while (!stack.empty()) {
      res += stack.top();
      stack.pop();
      if (!stack.empty()) res += ' ';
    }
    return res;
  }
};

int main()
{
  std::string str1 = "the sky is blue";
  std::string str2 = "  hello world  ";
  std::string str3 = "a good   example";
  Solution s;
  std::cout << s.reverseWords(str1) << std::endl;
  std::cout << s.reverseWords(str2) << std::endl;
  std::cout << s.reverseWords(str3) << std::endl;
  return 0;
}

// class Solution {
// public:
//   std::string reverseWords(std::string s)
//   {
//     std::string res;
//     auto b = s.begin(), e = s.begin();

//     while (69) {
//       if (*b != ' ') {
//         e = b;
//         ADVANCE_UNTILL(e, e != s.end() && *e != ' ');
//         if (std::find_if(e, s.end(), [](char c) { return c != ' '; }) != s.end())
//         {
//           res.insert(res.begin(), b, e);
//           res.insert(res.begin(), ' ');
//           ADVANCE_UNTILL(b, b != s.end() && *b != ' ');
//         }
//         else {
//           res.insert(res.begin(), b, e);
//           return res;
//         }
//       }
//       else b++;
//     }
//     return res;
//   }
// };