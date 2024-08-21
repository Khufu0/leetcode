#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

class Foo {
  int m_phase;
  std::mutex m_mutex;
  std::condition_variable m_cond;

public:
  Foo() : m_phase(1)
  {
  }

  void first(std::function<void()> printFirst)
  {
    std::scoped_lock lock(m_mutex);
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    m_phase = 2;
    m_cond.notify_all();
  }

  void second(std::function<void()> printSecond)
  {
    std::unique_lock lock(m_mutex);
    while (m_phase != 2) {
      m_cond.wait(lock);
    }
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    m_phase = 3;
    m_cond.notify_all();
  }

  void third(std::function<void()> printThird)
  {
    std::unique_lock lock(m_mutex);
    while (m_phase != 3) {
      m_cond.wait(lock);
    }
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};

int main()
{
  Foo s;
  std::vector<std::thread> threads(3);
  threads.at(0) =
      std::thread(&Foo::first, &s, [] { std::cout << "first" << std::endl; });
  threads.at(1) =
      std::thread(&Foo::second, &s, [] { std::cout << "second" << std::endl; });
  threads.at(2) =
      std::thread(&Foo::third, &s, [] { std::cout << "third" << std::endl; });

  for (auto &t : threads) {
    t.join();
  }
  return 0;
}