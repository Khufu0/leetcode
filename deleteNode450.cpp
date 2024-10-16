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
public:
  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (!root) return nullptr;
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
    }
    else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    }
    else {
      if (!root->left) {
        auto t = root->right;
        delete root;
        return t;
      }
      else if (!root->right) {
        auto t = root->left;
        delete root;
        return t;
      }
      else {
        auto t = getMin(root->right);
        root->val = t->val;
        root->right = deleteNode(root->right, t->val);
      }
    }
    return root;
  }

  TreeNode *getMin(TreeNode *node)
  {
    while (node->left) {
      node = node->left;
    }
    return node;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
