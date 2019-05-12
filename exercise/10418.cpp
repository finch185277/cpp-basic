#include <bits/stdc++.h>
using namespace std;

void solve(std::vector<std::vector<char>> &field, int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (field.at(i).at(j) == '*')
        continue;
      field.at(i).at(j) = '0';
      if (i - 1 >= 0 && field.at(i - 1).at(j) == '*')
        field.at(i).at(j)++;
      if (i + 1 < m && field.at(i + 1).at(j) == '*')
        field.at(i).at(j)++;
      if (j - 1 >= 0 && field.at(i).at(j - 1) == '*')
        field.at(i).at(j)++;
      if (j + 1 < n && field.at(i).at(j + 1) == '*')
        field.at(i).at(j)++;
      if (i - 1 >= 0 && j - 1 >= 0 && field.at(i - 1).at(j - 1) == '*')
        field.at(i).at(j)++;
      if (i - 1 >= 0 && j + 1 < n && field.at(i - 1).at(j + 1) == '*')
        field.at(i).at(j)++;
      if (i + 1 < m && j - 1 >= 0 && field.at(i + 1).at(j - 1) == '*')
        field.at(i).at(j)++;
      if (i + 1 < m && j + 1 < n && field.at(i + 1).at(j + 1) == '*')
        field.at(i).at(j)++;
    }
  }
}

int main() {
  for (int m, n, count = 1; std::cin >> m >> n, m != 0 && n != 0; count++) {
    if (count > 1)
      std::cout << std::endl;
    std::vector<std::vector<char>> field(m, std::vector<char>(n));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        std::cin >> field.at(i).at(j);
    solve(field, m, n);
    std::cout << "Field #" << count << ":" << std::endl;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
        std::cout << field.at(i).at(j);
      std::cout << std::endl;
    }
  }
}
