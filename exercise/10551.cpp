#include <bits/stdc++.h>
using namespace std;

int main() {
  std::vector<std::pair<int, int> > dp;
  dp.push_back(std::make_pair(0, 1)); // (factor, cluster size)
  dp.push_back(std::make_pair(0, 0)); // first case idx = 0 => (0,0)
  for (int idx; std::cin >> idx;) {
    if (dp.size() - 1 < idx) {           // if needed idx not saved
      for (; dp.front().second < idx;) { // do this when cluster size < idx
        int x = dp.back().first + 1, y = dp.back().second;
        dp.front().first++;
        dp.front().second += dp.front().first * 6;
        for (int j = 0; j < dp.front().first; j++) {
          dp.push_back(std::make_pair(--x, ++y));
        }
        for (int j = 0; j < dp.front().first; j++) {
          dp.push_back(std::make_pair(--x, y));
        }
        for (int j = 0; j < dp.front().first; j++) {
          dp.push_back(std::make_pair(x, --y));
        }
        for (int j = 0; j < dp.front().first; j++) {
          dp.push_back(std::make_pair(++x, --y));
        }
        for (int j = 0; j < dp.front().first; j++) {
          dp.push_back(std::make_pair(++x, y));
        }
        for (int j = 0; j < dp.front().first; j++) {
          dp.push_back(std::make_pair(x, ++y));
        }
      }
    }
    std::cout << dp.at(idx).first << " " << dp.at(idx).second << std::endl;
  }
}
