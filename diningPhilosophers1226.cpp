#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

class DiningPhilosophers {
  std::mutex mutex;
  std::condition_variable cond;
  int current_philosopher = 0;

public:
  DiningPhilosophers() = default;

  // this solution isn't efficent because it only allows one at a time
  void wantsToEat(int philosopher, std::function<void()> pickLeftFork,
                  std::function<void()> pickRightFork, std::function<void()> eat,
                  std::function<void()> putLeftFork,
                  std::function<void()> putRightFork)
  {
    std::unique_lock lock(mutex);
    cond.wait(lock, [&] { return current_philosopher == philosopher; });
    pickLeftFork();
    pickRightFork();
    eat();
    putLeftFork();
    putRightFork();
    current_philosopher + 1 == 5 ? current_philosopher = 0 : current_philosopher++;
    cond.notify_all();
  }
};

int main()
{
  std::cout << "no tests" << std::endl;
  return 0;
}