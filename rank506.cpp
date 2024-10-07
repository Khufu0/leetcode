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

class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &score)
  {
    struct player {
      player(size_t idx, int score) : idx(idx), score(score)
      {
      }

      size_t idx;
      int score;
    };

    struct less {
      constexpr bool operator()(const player &a, const player &b)
      {
        return a.score < b.score;
      }
    };

    priority_queue<player, vector<player>, less> pq;
    for (size_t i = 0; i < score.size(); i++)
      pq.emplace(i, score[i]);

    vector<string> res(score.size());
    int rank = 1;
    while (!pq.empty()) {
      auto [i, _] = pq.top();
      switch (rank) {
      case 1:
        res[i] = "Gold Medal";
        break;
      case 2:
        res[i] = "Silver Medal";
        break;
      case 3:
        res[i] = "Bronze Medal";
        break;
      default:
        res[i] = to_string(rank);
        break;
      }
      pq.pop(), rank++;
    }
    return res;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  Solution s;
  vector<int> v1 = {5, 4, 3, 2, 1};
  test(s.findRelativeRanks(v1) ==
       vector<string>{"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"});
  return 0;
}
