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

  void check(TreeNode *n, bool l, int c = -1)
  {
    if (!n) return;
    if (l) {
      check(n->right, false, ++c);
      check(n->left, true, 0);
    }
    else {
      check(n->left, true, ++c);
      check(n->right, false, 0);
    }
    res = max(res, c);
  }

public:
  int longestZigZag(TreeNode *root)
  {
    check(root, true);
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

/*
class Solution {
  int res = 0;

  void check(TreeNode *n, bool l, int c = -1)
  {
    if (!n) return;
    if (l) {
      c++;
      check(n->left, false, c);
    }
    if (!l) {
      c++;
      check(n->right, true, c);
    }
    res = max(res, c);
  }

  void dfs(TreeNode *root)
  {
    if (!root) return;
    check(root, true);
    check(root, false);
    dfs(root->left);
    dfs(root->right);
  }

public:
  int longestZigZag(TreeNode *root)
  {
    dfs(root);
    return res;
  }
};
*/