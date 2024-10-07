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
public:
  int maxDepth(TreeNode *root)
  {
    if (!root) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
