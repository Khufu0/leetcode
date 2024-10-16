#include <bits/stdc++.h>
using namespace std;

template <typename... T>
void pln(T... args)
{
  (cout << ... << args) << "\n";
}

void test(bool cond)
{
  if (cond) pln("Passed!!");
  else pln("Failed!!");
}

//----------------------------------------------------------------------------------
// #pragma GCC optimize("O3")
namespace {
static const bool __booster = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return true;
}();
} // namespace

class MinStack {
public:
  MinStack()
  {
  }

  void push(int val)
  {
    if (!m_container.empty()) m_container.push_back({val, min(val, getMin())});
    else m_container.push_back({val, val});
  }

  void pop()
  {
    m_container.pop_back();
  }

  int top()
  {
    return m_container.back().val;
  }

  int getMin()
  {
    return m_container.back().min;
  }

private:
  struct bucket {
    int val;
    int min;
  };

  vector<bucket> m_container;
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
