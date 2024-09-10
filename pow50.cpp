#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>

class Solution {
public:
  double myPow(double x, int n)
  {
    std::function<double(double x, int n)> recurse;
    recurse = [&](double x, int n) -> double {
      if (x == 0) return 0;
      if (n == 0) return 1;
      double res = recurse(x * x, n / 2);
      return (n % 2) ? res * x : res;
    };
    double res = recurse(x, std::abs(n));
    return (n >= 0) ? res : 1 / res;
  }

  // double myPow(double x, int n)
  // {
  //   bool neg = n < 0;
  //   if (neg) n = std::abs(n);
  //   double res = 1.;
  //   for (; n > 0; n--) {
  //     res *= x;
  //   }
  //   return neg ? 1 / res : res;
  // }
};

int main()
{
  double t11 = 2.5;
  int t12 = 2;
  double t21 = 69.69696969;
  int t22 = 69;
  double t31 = 2;
  int t32 = -2;

  Solution s;
  std::cout << s.myPow(t11, t12) << std::endl;
  std::cout << s.myPow(t21, t22) << std::endl;
  std::cout << s.myPow(t31, t32) << std::endl;

  return 0;
}