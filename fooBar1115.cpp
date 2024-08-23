#include <atomic>
#include <functional>
#include <thread>

// lock free
// submitted it multiple times (same code) every submission kept getting lower
// runtime
class FooBar {
private:
  int n;
  std::atomic_bool m_foo;

public:
  FooBar(int n) : n(n)
  {
  }

  void foo(std::function<void()> printFoo)
  {
    for (int i = 0; i < n; i++) {
      while (m_foo.load(std::memory_order::acquire))
        std::this_thread::yield();
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      m_foo.store(true, std::memory_order_release);
    }
  }

  void bar(std::function<void()> printBar)
  {
    for (int i = 0; i < n; i++) {
      while (!m_foo.load(std::memory_order::acquire))
        std::this_thread::yield();
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      m_foo.store(false, std::memory_order_release);
    }
  }
};

int main()
{
  return 0;
}