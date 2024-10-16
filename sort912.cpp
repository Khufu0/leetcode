#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
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

class timer {
public:
  using time_t = std::chrono::time_point<std::chrono::high_resolution_clock>;

  timer(const char *name = "")
      : m_name(name), m_start(std::chrono::high_resolution_clock::now())
  {
    pln(m_name, " starting");
  }

  ~timer()
  {
    pln(m_name, " duration: ",
        std::chrono::duration<double>(std::chrono::high_resolution_clock::now() -
                                      m_start));
  }

private:
  const char *m_name;
  time_t m_start;
};

//----------------------------------------------------------------------------------
#define MIN 128

class Solution {
  void insertionSort(vector<int> &nums)
  {
    for (size_t i = 1; i < nums.size(); i++) {
      int num = nums[i];
      int j = i - 1;
      while (j >= 0 && num < nums[j]) {
        nums[j + 1] = nums[j];
        j--;
      }
      nums[j + 1] = num;
    }
  }

  void mergeSort(vector<int> &nums)
  {
    size_t n = nums.size();
    if (n <= 1) return;

    size_t middle = n / 2;
    vector<int> left(middle);
    vector<int> right(n - middle);
    size_t i = 0, j = middle;

    while (i < middle || j < n) {
      if (i < middle) {
        left[i] = nums[i];
        i++;
      }
      if (j < n) {
        right[j - middle] = nums[j];
        j++;
      }
    }
    if (n <= MIN) {
      insertionSort(left);
      insertionSort(right);
    }
    else {
      mergeSort(left);
      mergeSort(right);
    }
    merge(left, right, nums);
  }

  void merge(vector<int> &left, vector<int> &right, vector<int> &out)
  {
    size_t ln = left.size();
    size_t rn = right.size();
    size_t i = 0, l = 0, r = 0;

    while (l < ln && r < rn) {
      if (left[l] <= right[r]) {
        out[i] = left[l];
        l++;
      }
      else if (left[l] > right[r]) {
        out[i] = right[r];
        r++;
      }
      i++;
    }
    while (l < ln) {
      out[i] = left[l];
      l++;
      i++;
    }
    while (r < rn) {
      out[i] = right[r];
      r++;
      i++;
    }
  }

public:
  vector<int> sortArray(vector<int> &nums)
  {
    mergeSort(nums);
    return nums;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  random_device rd;
  uniform_int_distribution dist(0, 1000000);
  vector<int> v1(10000000);
  for (int &i : v1)
    i = dist(rd);

  Solution s;
  vector v2 = v1;
  {
    timer t("merge");
    s.sortArray(v1);
  }
  {
    timer t("std");
    ranges::sort(v2);
  }
  test(v1 == v2);
}

// class Solution {
//   void heapSort(vector<int> &nums)
//   {
//     size_t n = nums.size();
//     if (n <= 1) return;
//     ranges::make_heap(nums);
//     while (n > 0) {
//       ranges::pop_heap(nums.begin(), nums.begin() + n);
//       n--;
//     }
//   }

// public:
//   vector<int> sortArray(vector<int> &nums)
//   {
//     heapSort(nums);
//     return nums;
//   }
// };
