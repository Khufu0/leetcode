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
    int temp;
    size_t idx;
  };

public:
  vector<int> dailyTemperatures(vector<int> &temps)
  {
    size_t n = temps.size();
    vector<int> res(n, 0);
    stack<Data> mono;
    for (size_t i = 0; i < n; i++) {
      while (!mono.empty() && temps[i] > mono.top().temp) {
        size_t idx = mono.top().idx;
        res[idx] = i - idx;
        mono.pop();
      }
      mono.push({temps[i], i});
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
