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

class SmallestInfiniteSet {
  int curr = 1;
  set<int> set;

public:
  SmallestInfiniteSet()
  {
  }

  int popSmallest()
  {
    if (!set.empty()) return set.extract(*set.begin()).value();
    return curr++;
  }

  void addBack(int num)
  {
    if (num < curr) set.insert(num);
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
