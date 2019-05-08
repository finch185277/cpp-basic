#include <bits/stdc++.h>

using namespace std;

inline bool check(std::vector<std::vector<char>> &board, int i, int j,
                  char val) {
  int row = i - i % 3, col = j - j % 3;
  for (int x = 0; x < 9; x++) // same column
    if (board.at(x).at(j) == val)
      return false;
  for (int y = 0; y < 9; y++) // same row
    if (board.at(i).at(y) == val)
      return false;
  for (int x = 0; x < 3; x++) // same block
    for (int y = 0; y < 3; y++)
      if (board.at(row + x).at(col + y) == val)
        return false;
  return true;
}

inline bool solve(std::vector<std::vector<char>> &board, int i, int j) {
  if (i == 9) // buttom upper bound
    return true;
  if (j == 9) // right upper bound
    return solve(board, i + 1, 0);
  if (board.at(i).at(j) != '.')
    return solve(board, i, j + 1);
  for (char c = '1'; c <= '9'; c++) { // if current cell unknown
    if (check(board, i, j, c)) {      // DFS
      board.at(i).at(j) = c;
      if (solve(board, i, j + 1))
        return true;
      board.at(i).at(j) = '.'; // back and forward
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
