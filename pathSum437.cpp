#include <bits/stdc++.h>
using namespace std;

template <typename... T>
void pln(T... args)
{
  (cout << ... << args) << "\n";
}

void test(bool cond)
{
  if (cond) pln("Passed!!");
  else pln("Failed!!");
}

//----------------------------------------------------------------------------------
// #pragma GCC optimize("O3")
namespace {
static const bool __booster = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
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
  int res = 0;
  int target = 0;

  void check(TreeNode *n, long long sum)
  {
    if (!n) return;
    sum += n->val;
    if (sum == target) res++;
    check(n->left, sum);
    check(n->right, sum);
  }

  void dfs(TreeNode *root)
  {
    if (!root) return;
    check(root, 0);
    dfs(root->left);
    dfs(root->right);
  }

public:
  int pathSum(TreeNode *root, int targetSum)
  {
    target = targetSum;
    dfs(root);
    return res;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
