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
  // O(Nlg(K))
  int findKthLargest(vector<int> &nums, int k)
  {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i : nums) {
      pq.push(i);
      if (pq.size() > k) {
        pq.pop();
      }
    }
    return pq.top();
  }

  // O(Nlg(N))
  // int findKthLargest(vector<int> &nums, int k)
  // {
  //   priority_queue<int> pq;
  //   for (auto i : nums) {
  //     pq.push(i);
  //   }
  //   while (--k) {
  //     pq.pop();
  //   }
  //   return pq.top();
  // }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
