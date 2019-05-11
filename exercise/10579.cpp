#include <bits/stdc++.h>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int m, n;
  std::cin >> m >> n;
  std::map<std::string, int> dic;
  while (m--) {
    std::string word;
    int value;
    std::cin >> word >> value;
    dic.insert(std::make_pair(word, value));
  }
  int sum = 0;
  for (std::string line; std::getline(std::cin, line);) {
    if (line == ".") {
      std::cout << sum << std::endl;
      sum = 0;
    }
    std::stringstream ss(line);
    std::string word;
    while (ss >> word) {
      if (dic.count(word))
        sum += dic[word];
    }
  }
  return 0;
}
