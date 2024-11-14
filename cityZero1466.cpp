#include <bits/stdc++.h>
using namespace std;

template <typename... T>
void pln(T... args)
{
  (cout << ... << args) << '\n';
}

void test(bool cond)
{
  if (cond) pln("Passed!!");
  else pln("Failed!!");
}

//----------------------------------------------------------------------------------
namespace {
static const bool __booster = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return true;
}();
} // namespace

class Solution {
  int dfs(vector<vector<int>> &al, vector<bool> &visited, int from)
  {
    int change = 0;
    visited[from] = true;
    for (int to : al[from])
      if (!visited[abs(to)]) change += dfs(al, visited, abs(to)) + (to > 0);
    return change;
  }

public:
  int minReorder(int n, vector<vector<int>> &connections)
  {
    vector<vector<int>> al(n);
    for (auto &c : connections) {
      al[c[0]].push_back(c[1]);
      al[c[1]].push_back(-c[0]);
    }
    return dfs(al, vector<bool>(n) = {}, 0);
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
