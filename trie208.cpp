#include <bits/stdc++.h>
using namespace std;

template <typename... T>
void pln(T... args)
{
  (cout << ... << args) << '\n';
}

void test(bool cond)
{
  if (cond) pln("Passed!!");
  else pln("Failed!!");
}

//----------------------------------------------------------------------------------
namespace {
static const bool __booster = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return true;
}();
} // namespace

class Trie {
  struct Node {
    unordered_map<char, Node> hashmapuh;
    bool word = false;
  } head;

public:
  Trie() = default;

  void insert(string word)
  {
    Node *current_node = &head;
    for (char c : word) {
      if (!current_node->hashmapuh.contains(c)) {
        current_node->hashmapuh[c] = {};
      }
      current_node = &current_node->hashmapuh[c];
    }
    current_node->word = true;
  }

  bool search(string word)
  {
    Node *current_node = &head;
    for (char c : word) {
      if (!current_node->hashmapuh.contains(c)) {
        return false;
      }
      current_node = &current_node->hashmapuh[c];
    }
    return current_node->word;
  }

  bool startsWith(string prefix)
  {
    Node *current_node = &head;
    for (char c : prefix) {
      if (!current_node->hashmapuh.contains(c)) {
        return false;
      }
      current_node = &current_node->hashmapuh[c];
    }
    return true;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
