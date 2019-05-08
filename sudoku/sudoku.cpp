#include <bits/stdc++.h>

using namespace std;

inline bool check(std::vector<std::vector<char>> &board, int i, int j,
                  char val) {
  for (int k = 0; k < 9; k++) {
    if (board.at(i).at(k) == val)
      return false;
    if (board.at(k).at(j) == val)
      return false;
  }
  for (int x = (i / 3) * 3; x < (i / 3) * 3 + 3; x++)
    for (int y = (j / 3) * 3; y < (j / 3) * 3 + 3; y++)
      if (board.at(x).at(y) == val)
        return false;
  return true;
}

inline bool solve(std::vector<std::vector<char>> &board, int i, int j) {
  if (i == 9)
    return true;
  if (j == 9)
    return solve(board, i + 1, 0);
  if (board.at(i).at(j) != '.')
    return solve(board, i, j + 1);
  for (char c = '1'; c <= '9'; c++) {
    if (check(board, i, j, c)) {
      board.at(i).at(j) = c;
      if (solve(board, i, j + 1))
        return true;
      board.at(i).at(j) = '.';
    }
  }
  return false;
}

inline void solveSudoku(vector<vector<char>> &board) { solve(board, 0, 0); }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::vector<std::vector<char>> board;
  for (std::string line; std::getline(cin, line);) {
    std::stringstream line_ss;
    std::vector<char> line_vec;
    line_ss << line;
    for (char c; line_ss >> c;)
      line_vec.push_back(c);
    board.push_back(line_vec);
  }
  solveSudoku(board);
  for (std::vector<char> &line : board) {
    for (char &c : line)
      std::cout << c << ' ';
    std::cout << std::endl;
  }
  return 0;
}
