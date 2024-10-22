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

class UF {
public:
  UF(size_t n) : m_id(n), m_size(n, 1), m_count(n)
  {
    iota(m_id.begin(), m_id.end(), 0);
  }

  size_t root(size_t a)
  {
    while (a != m_id[a]) {
      a = m_id[a];
    }
    return a;
  }

  bool connected(size_t a, size_t b)
  {
    return root(a) == root(b);
  }

  void unite(size_t a, size_t b)
  {
    size_t ra = root(a);
    size_t rb = root(b);
    if (ra == rb) return;
    if (m_size[ra] < m_size[rb]) {
      m_id[ra] = rb;
      m_size[rb] += m_size[ra];
    }
    else {
      m_id[rb] = ra;
      m_size[ra] += m_size[rb];
    }
    m_count--;
  }

  size_t provinces()
  {
    return m_count;
  }

private:
  std::vector<size_t> m_id;
  std::vector<size_t> m_size;
  size_t m_count;
};

class Solution {
public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    size_t n = isConnected.size();
    UF uf(n);
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        if (isConnected[i][j]) {
          uf.unite(i, j);
        }
      }
    }
    return uf.provinces();
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  vector<vector<int>> v = {{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
                           {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1}};
  Solution s;
  test(s.findCircleNum(v) == 6);
  return 0;
}
