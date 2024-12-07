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
    double ratio;
    int quality;

    constexpr auto operator<=>(const Data &x) const noexcept
    {
      return ratio <=> x.ratio;
    }
  };

public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
  {
    int n = quality.size();
    vector<Data> data(n);
    for (int i = 0; i < n; i++) {
      data[i] = {wage[i] / double(quality[i]), quality[i]};
    }
    ranges::sort(data, less<Data>()); // sort by ratio asc
    priority_queue<int> pq;           // max heap quality
    double minCost = numeric_limits<double>::max();
    int totalQuality = 0;
    for (auto &d : data) {
      pq.push(d.quality);
      totalQuality += d.quality;
      if (pq.size() > k) {
        totalQuality -= pq.top();
        pq.pop();
      }
      if (pq.size() == k) minCost = min(minCost, totalQuality * d.ratio);
    }
    return minCost;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
