#include <condition_variable>
#include <functional>
#include <iostream>
#include <thread>

class FizzBuzz {
private:
  int n;
  int c;
  std::mutex m_mutex;
  std::condition_variable m_cond;

public:
  FizzBuzz(int n) : n(n), c(1)
  {
  }

  template <typename Predicate, typename Printer, typename... Args>
    requires std::is_invocable_v<Predicate> && std::is_invocable_v<Printer, Args...>
  inline void print(Predicate &&pred, Printer &&printer, Args &&...args)
  {
    std::unique_lock lock(m_mutex);
    while (c <= n) {
      m_cond.wait(lock, pred);
      if (c <= n) [[likely]] {
        printer(std::forward<Args>(args)...);
        c++;
      }
      m_cond.notify_all(); // notify all to check their luck
    }
  }

  void fizz(std::function<void()> printFizz)
  {
    print([&] { return c > n || ((c % 3 == 0) && (c % 5 != 0)); },
          std::move(printFizz));
  }

  void buzz(std::function<void()> printBuzz)
  {
    print([&] { return c > n || ((c % 3 != 0) && (c % 5 == 0)); },
          std::move(printBuzz));
  }

  void fizzbuzz(std::function<void()> printFizzBuzz)
  {
    print([&] { return c > n || ((c % 3 == 0) && (c % 5 == 0)); },
          std::move(printFizzBuzz));
  }

  void number(std::function<void(int)> printNumber)
  {
    print([&] { return c > n || ((c % 3 != 0) && (c % 5 != 0)); },
          std::move(printNumber), std::ref(c));
  }
};

int main()
{
  FizzBuzz s(15);
  std::vector<std::thread> threads(4);
  threads.at(0) =
      std::thread(&FizzBuzz::fizz, &s, [] { std::cout << "fizz" << std::endl; });
  threads.at(1) =
      std::thread(&FizzBuzz::buzz, &s, [] { std::cout << "buzz" << std::endl; });
  threads.at(2) = std::thread(&FizzBuzz::fizzbuzz, &s,
                              [] { std::cout << "fizzbuzz" << std::endl; });
  threads.at(3) =
      std::thread(&FizzBuzz::number, &s, [](int i) { std::cout << i << std::endl; });

  for (auto &t : threads) {
    t.join();
  }
  return 0;
}
