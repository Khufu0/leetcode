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
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    vector<int> res;
    int l = 0, r = numbers.size() - 1;
    while (l < r) {
      int sum = numbers[l] + numbers[r];
      if (sum > target) r--;
      else if (sum < target) l++;
      else return {l + 1, r + 1};
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

// class Solution {
// public:
//   vector<int> twoSum(vector<int> &numbers, int target)
//   {
//     vector<int> res;
//     for (size_t i = 0; i < numbers.size(); i++) {
//       for (size_t j = 0; j < numbers.size(); j++) {
//         if (i != j && numbers[i] + numbers[j] == target) {
//           res.push_back(i + 1);
//           res.push_back(j + 1);
//           goto ret;
//         }
//       }
//     }
//   ret:
//     return res;
//   }
// };

// class Solution {
// public:
//   vector<int> twoSum(vector<int> &numbers, int target)
//   {
//     vector<int> res;
//     unordered_map<int, size_t> map;
//     for (size_t i = 0; i < numbers.size(); i++) {
//       map[numbers[i]] = i;
//     }
//     for (size_t i = 0; i < numbers.size(); i++) {
//       auto f = map.find(target - numbers[i]);
//       if (f != map.end() && i != (*f).second) {
//         res.push_back(1 + i);
//         res.push_back(1 + (*f).second);
//         break;
//       }
//     }
//     return res;
//   }
// };