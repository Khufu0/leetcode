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
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    vector<int> res;
    unordered_map<int, int> hmap;
    for (auto n : nums) {
      hmap[n]++;
    }
    // indexed by frequency
    vector<vector<int>> freq(nums.size() + 1);
    for (auto &p : hmap) {
      freq[p.second].emplace_back(p.first);
    }

    for (auto it = freq.rbegin(); it != freq.rend(); it++) {
      for (auto n : *it) {
        res.emplace_back(n);
        if (res.size() == k) return res;
      }
    }
    return res;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  vector v1{1, 1, 1, 2, 2, 3};
  test(s.topKFrequent(v1, 2) == vector{1, 2});
  return 0;
}

/*
class Solution {
  struct Data {
    int f = 1;
    int n = 0;

    auto operator<=>(const Data &rhs) const
    {
      return f <=> rhs.f;
    }
  };

public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    ranges::sort(nums);
    // min heap
    priority_queue<Data, vector<Data>, greater<Data>> pq;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      Data d;
      d.n = nums[i];
      while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        d.f++;
        i++;
      }
      if (pq.size() == k) {
        if (pq.top() < d) pq.pop();
        else continue;
      }
      pq.emplace(d);
    }
    while (k--) {
      res.emplace_back(pq.top().n);
      pq.pop();
    }
    return res;
  }
};
*/