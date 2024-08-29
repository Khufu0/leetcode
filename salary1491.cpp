#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  double average(std::vector<int> &salary)
  {
    int min = salary.at(0);
    int max = 0;
    double res = 0.0;
    for (int i : salary) {
      res += i;
      if (i < min) {
        min = i;
      }
      else if (i > max) {
        max = i;
      }
    }
    std::cout << min << " " << max << std::endl;
    res -= min;
    res -= max;
    return res / (salary.size() - 2);
  }
};

int main()
{
  std::vector<int> t1 = {4000, 3000, 1000, 2000};
  std::vector<int> t2 = {25000, 48000, 57000, 86000, 33000, 10000,
                         42000, 3000,  54000, 29000, 79000, 40000};
  Solution s;
  std::cout << s.average(t1) << std::endl;
  std::cout << s.average(t2) << std::endl;
  return 0;
}