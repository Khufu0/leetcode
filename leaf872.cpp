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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr)
  {
  }

  TreeNode(int x) : val(x), left(nullptr), right(nullptr)
  {
  }

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
  {
  }
};

class Solution {
  void recurse(TreeNode *head, vector<int> &v)
  {
    if (!head) return;
    if (!head->left && !head->right) {
      v.push_back(head->val);
      return;
    }
    recurse(head->left, v);
    recurse(head->right, v);
  }

public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2)
  {
    vector<int> v1;
    vector<int> v2;
    recurse(root1, v1);
    recurse(root2, v2);
    return v1 == v2;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
