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
  int maxLevelSum(TreeNode *root)
  {
    deque<TreeNode *> q = {root};
    int level = 1;
    int m = numeric_limits<int>::min();
    int res = 1;
    while (!q.empty()) {
      size_t s = q.size();
      int levelSum = 0;
      for (; s > 0; s--) {
        TreeNode *n = q.front();
        levelSum += n->val;
        q.pop_front();
        if (n->left) q.push_back(n->left);
        if (n->right) q.push_back(n->right);
      }
      if (levelSum > m) {
        res = level;
        m = levelSum;
      }
      level++;
    }
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
