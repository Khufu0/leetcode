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
  struct Data {
    int s;
    int e;

    constexpr auto operator<=>(const Data &x) const noexcept
    {
      return e <=> x.e;
    }
  };

public:
  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
  {
    vector<Data> v;
    for (int i = 0; i < n; i++)
      v.emplace_back(speed[i], efficiency[i]);
    ranges::sort(v, greater<Data>());                  // descending based on Data.e
    priority_queue<int, vector<int>, greater<int>> pq; // min heap for Data.s
    long long sum = 0;
    long long res = 0;
    for (auto &d : v) {
      pq.push(d.s);
      sum += d.s;
      if (pq.size() > k) {
        sum -= pq.top();
        pq.pop();
      }
      if (pq.size() <= k) res = max(res, sum * d.e);
    }
    return res % static_cast<long long>(pow(10, 9) + 7);
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
