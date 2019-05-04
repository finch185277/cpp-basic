#include <bits/stdc++.h>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int case_num;
  std::string case_str;
  std::stringstream case_ss;
  std::getline(std::cin, case_str);
  case_ss << case_str;
  case_ss >> case_num;
  while (case_num--) {
    std::vector<int> packages;
    for (std::string pack_str; std::getline(std::cin, pack_str, ' ');)
      packages.push_back(std::stoi(pack_str));
    int sum = 0;
    bool skip = false;
    for (int &p : packages)
      sum += p;
    if (sum % 2) {
      std::cout << "NO" << std::endl;
      continue;
    }
    sum /= 2;
    std::vector<bool> dp(sum + 1, false);
    for (int &p : packages) {
      if (p > sum) {
        std::cout << "NO" << std::endl;
        skip = true;
        break;
      }
      for (int i = 1; i < dp.size(); i++) {
        if (dp.at(i) && i + p < dp.size()) {
          dp.at(i + p) = true;
        }
      }
      dp.at(p) = true;
    }
    if (!skip) {
      if (dp.back())
        std::cout << "YES" << std::endl;
      else
        std::cout << "NO" << std::endl;
    }
  }
}
