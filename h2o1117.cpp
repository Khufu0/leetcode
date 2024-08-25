#include <condition_variable>
#include <functional>
#include <iostream>
#include <syncstream>
#include <thread>
#include <vector>

class H2O {
private:
  static inline int h = 0;
  static inline bool o = false;
  static inline std::condition_variable cond;
  static inline std::mutex mutex;

public:
  H2O()
  {
  }

  void oxygen(std::function<void()> releaseOxygen)
  {
    std::unique_lock lock(mutex);
    cond.wait(lock, [] { return o == true; });
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseOxygen();
    o = false;
    cond.notify_all();
  }

  void hydrogen(std::function<void()> releaseHydrogen)
  {
    std::unique_lock lock(mutex);
    cond.wait(lock, [] { return o == false; });
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseHydrogen();
    h++;
    if (h % 2 == 0)
      o = true;
    cond.notify_all();
  }
};

int main()
{
  H2O s1;

  std::vector<std::thread> threads(6);

  threads.at(0) =
      std::thread(&H2O::hydrogen, &s1, [] { std::osyncstream(std::cout) << "H"; });
  threads.at(1) =
      std::thread(&H2O::hydrogen, &s1, [] { std::osyncstream(std::cout) << "H"; });
  threads.at(2) =
      std::thread(&H2O::oxygen, &s1, [] { std::osyncstream(std::cout) << "O"; });

  H2O s2;
  threads.at(3) =
      std::thread(&H2O::hydrogen, &s2, [] { std::osyncstream(std::cout) << "H"; });
  threads.at(4) =
      std::thread(&H2O::hydrogen, &s2, [] { std::osyncstream(std::cout) << "H"; });
  threads.at(5) =
      std::thread(&H2O::oxygen, &s2, [] { std::osyncstream(std::cout) << "O"; });

  for (auto &t : threads) {
    t.join();
  }

  std::cout << std::endl;

  return 0;
}