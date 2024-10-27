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
    int val;
    int min;

    constexpr auto operator<=>(const Data &x) const noexcept
    {
      return min <=> x.min;
    }
  };

public:
  long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
  {
    size_t n = nums1.size();
    vector<Data> v;
    for (size_t i = 0; i < n; i++)
      v.emplace_back(nums1[i], nums2[i]);
    ranges::sort(v, greater<Data>()); // descending based on Data.min
    priority_queue<int, vector<int>, greater<int>> pq; // min heap for Data.val
    long long n1sum = 0;
    long long res = 0;
    for (auto &d : v) {
      pq.push(d.val);
      n1sum += d.val;
      if (pq.size() > k) {
        n1sum -= pq.top();
        pq.pop();
      }
      if (pq.size() == k) res = max(res, n1sum * d.min);
    }
    return res;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  vector v1 = {1, 3, 3, 2};
  vector v2 = {2, 1, 3, 4};
  test(s.maxScore(v1, v2, 3) == 12);
  return 0;
}
