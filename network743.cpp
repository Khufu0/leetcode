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
  struct Edge {
    int d;
    int w;

    friend auto operator<=>(const Edge &lhs, const Edge &rhs)
    {
      return lhs.w <=> rhs.w;
    }
  };

public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {
    unordered_map<int, vector<Edge>> adj(n);
    for (vector<int> &edge : times) {
      int s = edge[0], d = edge[1], w = edge[2];
      adj[s].emplace_back(d, w);
    }
    int time = numeric_limits<int>::min();
    unordered_set<int> visited;
    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;
    minHeap.emplace(k, 0);
    while (!minHeap.empty()) {
      auto [currd, currw] = minHeap.top();
      minHeap.pop();
      if (visited.contains(currd)) continue;
      time = max(time, currw);
      visited.emplace(currd);
      for (auto &[d1, w1] : adj[currd]) {
        if (!visited.contains(d1)) minHeap.emplace(d1, currw + w1);
      }
    }
    return visited.size() == n ? time : -1;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
