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
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms)
  {
    unordered_set<int> visited;
    stack<int> stack;
    stack.push(0);
    while (!stack.empty()) {
      int node = stack.top();
      stack.pop();
      visited.emplace(node);
      for (auto n : rooms[node]) {
        if (!visited.contains(n)) stack.push(n);
      }
    }
    return visited.size() == rooms.size();
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
