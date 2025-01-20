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

  void insert(const string &word)
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

  vector<string> getWords(string &prefix)
  {
    auto *node = &head;
    for (char c : prefix) {
      if (!node->hashmapuh.contains(c)) {
        return {};
      }
      node = &node->hashmapuh.at(c);
    }
    vector<string> res;
    dfs(node, prefix, res);
    return res;
  }

  void dfs(const Node *node, string &prefix, vector<string> &words)
  {
    // add only 3 words to words vector
    if (words.size() == 3) {
      return;
    }
    if (node->word) {
      words.emplace_back(prefix);
    }
    for (size_t i = 0; i < 26; i++) {
      char c = 'a' + i;
      if (!node->hashmapuh.contains(c)) {
        continue;
      }
      prefix.push_back(c);
      dfs(&node->hashmapuh.at(c), prefix, words);
      prefix.pop_back();
    }
  }
};

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord)
  {
    Trie trie;
    for (auto &p : products) {
      trie.insert(p);
    }
    vector<vector<string>> res;
    string pref = "";
    for (size_t i = 0; i < searchWord.size(); i++) {
      pref += searchWord[i];
      const auto words = trie.getWords(pref);
      res.emplace_back(words.begin(),
                       words.size() > 3 ? words.begin() + 3 : words.end());
    }
    return res;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  //   Solution s;
  pln("NO TESTS!");
  return 0;
}
