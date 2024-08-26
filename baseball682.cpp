#include <iostream>
#include <list>
#include <numeric>
#include <vector>

class Solution {
public:
  int calPoints(std::vector<std::string> &operations)
  {
    std::list<int> scores;

    for (auto &o : operations) {
      if (o == "+") {
        scores.push_back(scores.back() + *(std::next(scores.rbegin())));
      }
      else if (o == "D") {
        scores.push_back(scores.back() * 2);
      }
      else if (o == "C") {
        scores.pop_back();
      }
      else [[likely]] {
        scores.push_back(std::stoi(o));
      }
    }

    return std::accumulate(scores.begin(), scores.end(), 0);
  }
};

int main()
{
  std::vector<std::string> t1 = {"5", "2", "C", "D", "+"};
  std::vector<std::string> t2 = {"5", "-2", "4", "C", "D", "9", "+", "+"};
  std::vector<std::string> t3 = {"1", "C"};

  Solution s;
  std::cout << s.calPoints(t1) << std::endl;
  std::cout << s.calPoints(t2) << std::endl;
  std::cout << s.calPoints(t3) << std::endl;

  return 0;
}