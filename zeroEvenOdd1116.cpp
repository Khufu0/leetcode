#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>

class ZeroEvenOdd {
private:
  int n;
  int i;
  bool z;
  std::mutex mutex;
  std::condition_variable cond;

public:
  ZeroEvenOdd(int n) : n(n), i(1), z(true)
  {
  }

  void zero(std::function<void(int)> printNumber)
  {
    std::unique_lock lock(mutex);
    while (69) {
      cond.wait(lock, [&] { return z == true || i > n; });

      if (i > n)
        break;

      printNumber(0);
      z = false;
      cond.notify_all();
    }
  }

  void even(std::function<void(int)> printNumber)
  {
    std::unique_lock lock(mutex);
    while (69) {
      cond.wait(lock, [&] { return (z == false && i % 2 == 0) || i > n; });

      if (i > n) [[unlikely]]
        break;

      printNumber(i);
      i++;
      z = true;
      cond.notify_all();
    }
  }

  void odd(std::function<void(int)> printNumber)
  {
    std::unique_lock lock(mutex);
    while (69) {
      cond.wait(lock, [&] { return (z == false && i % 2 != 0) || i > n; });

      if (i > n) [[unlikely]]
        break;

      printNumber(i);
      i++;
      z = true;
      cond.notify_all();
    }
  }
};

int main()
{
  ZeroEvenOdd s1(12);

  std::vector<std::thread> threads(3);
  threads.at(0) =
      std::thread(&ZeroEvenOdd::zero, &s1, [](int i) { std::cout << i; });
  threads.at(1) =
      std::thread(&ZeroEvenOdd::even, &s1, [](int i) { std::cout << i; });
  threads.at(2) = std::thread(&ZeroEvenOdd::odd, &s1, [](int i) { std::cout << i; });

  for (auto &t : threads) {
    t.join();
  }
  std::cout << std::endl;

  ZeroEvenOdd s2(1);

  threads.at(0) =
      std::thread(&ZeroEvenOdd::zero, &s2, [](int i) { std::cout << i; });
  threads.at(1) =
      std::thread(&ZeroEvenOdd::even, &s2, [](int i) { std::cout << i; });
  threads.at(2) = std::thread(&ZeroEvenOdd::odd, &s2, [](int i) { std::cout << i; });

  for (auto &t : threads) {
    t.join();
  }
  std::cout << std::endl;

  return 0;
}