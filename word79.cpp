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

class Solution {
  bool backtrack(vector<vector<char>> &board, const string &word, int i,
                 vector<vector<bool>> &visited, int r, int c)
  {
    if (i == word.size()) {
      return true;
    }
    if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
        visited[r][c] || board[r][c] != word[i]) {
      return false;
    }

    visited[r][c] = true;
    bool res = backtrack(board, word, i + 1, visited, r + 1, c) ||
               backtrack(board, word, i + 1, visited, r, c + 1) ||
               backtrack(board, word, i + 1, visited, r - 1, c) ||
               backtrack(board, word, i + 1, visited, r, c - 1);
    visited[r][c] = false;
    return res;
  }

public:
  bool exist(vector<vector<char>> &board, string word)
  {
    vector<vector<bool>> visited(board.size());
    for (auto &v : visited) {
      v.resize(board[0].size());
    }
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (backtrack(board, word, 0, visited, i, j)) return true;
      }
    }
    return false;
  }
};

//----------------------------------------------------------------------------------

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
  vector<vector<char>> board1 = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  vector<vector<char>> board2 = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  vector<vector<char>> board3 = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  vector<vector<char>> board4 = {
      {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}};
  vector<vector<char>> board5 = {{'a', 'b'}, {'c', 'd'}};
  test(Solution().exist(board1, "ABCCED") == true);
  test(Solution().exist(board2, "SEE") == true);
  test(Solution().exist(board3, "ABCB") == false);
  test(Solution().exist(board4, "AAAAAAAAAAAAAAB") == false);
  test(Solution().exist(board5, "bacd") == true);
  return 0;
}

/*
class Solution {
  bool res = false;

  void backtrack(vector<vector<char>> &board, const string &word, string &current,
                 set<pair<int, int>> &visited, int r, int c)
  {
    visited.emplace(r, c);
    current += board[r][c];
    if (current == word) {
      res = true;
      return;
    }
    if (current.size() == word.size()) {
      visited.erase({r, c});
      current.pop_back();
      return;
    }
    if (board[r][c] != word[current.size() - 1]) {
      visited.erase({r, c});
      current.pop_back();
      return;
    }

    if (!res && !visited.contains({r + 1, c}) && r + 1 < board.size()) {
      backtrack(board, word, current, visited, r + 1, c);
    }
    if (!res && !visited.contains({r, c + 1}) && c + 1 < board[0].size()) {
      backtrack(board, word, current, visited, r, c + 1);
    }
    if (!res && !visited.contains({r - 1, c}) && r - 1 >= 0) {
      backtrack(board, word, current, visited, r - 1, c);
    }
    if (!res && !visited.contains({r, c - 1}) && c - 1 >= 0) {
      backtrack(board, word, current, visited, r, c - 1);
    }
    visited.erase({r, c});
    current.pop_back();
  }

public:
  bool exist(vector<vector<char>> &board, string word)
  {
    set<pair<int, int>> visited;
    string s;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (!res && board[i][j] == word[0]) {
          backtrack(board, word, s, visited, i, j);
        }
      }
    }
    return res;
  }
};
*/

/*
class Solution {
  bool res = false;

  void backtrack(vector<vector<char>> &board, const string &word, string &current,
                 vector<vector<bool>> &visited, int r, int c)
  {
    visited[r][c] = true;
    current += board[r][c];
    if (current == word) {
      res = true;
      return;
    }
    if (current.size() == word.size()) {
      visited[r][c] = false;
      current.pop_back();
      return;
    }
    if (board[r][c] != word[current.size() - 1]) {
      visited[r][c] = false;
      current.pop_back();
      return;
    }

    if (!res && r + 1 < board.size() && !visited[r + 1][c]) {
      backtrack(board, word, current, visited, r + 1, c);
    }
    if (!res && c + 1 < board[0].size() && !visited[r][c + 1]) {
      backtrack(board, word, current, visited, r, c + 1);
    }
    if (!res && r - 1 >= 0 && !visited[r - 1][c]) {
      backtrack(board, word, current, visited, r - 1, c);
    }
    if (!res && c - 1 >= 0 && !visited[r][c - 1]) {
      backtrack(board, word, current, visited, r, c - 1);
    }
    visited[r][c] = false;
    current.pop_back();
  }

public:
  bool exist(vector<vector<char>> &board, string word)
  {
    vector<vector<bool>> visited(board.size());
    for (auto &v : visited) {
      v.resize(board[0].size());
    }
    string s;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (!res && board[i][j] == word[0]) {
          backtrack(board, word, s, visited, i, j);
        }
      }
    }
    return res;
  }
};
*/