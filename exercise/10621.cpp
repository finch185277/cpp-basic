#include <bits/stdc++.h>
using namespace std;

int main() {
  int case_num;
  std::string case_str;
  std::stringstream case_ss;
  std::getline(std::cin, case_str);
  case_ss << case_str;
  case_ss >> case_num;
  while (case_num--) {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream line_ss;
    line_ss << line;
    std::vector<int> packages;
    int tatal_weight = 0;
    for (int w; line_ss >> w;) {
      tatal_weight += w;
      packages.push_back(w);
    }
    if (tatal_weight % 2) {
      std::cout << "NO" << std::endl;
      continue;
    }
    int ideal_weight = tatal_weight / 2;
    std::vector<bool> dp(ideal_weight + 1, false);
    bool skip = false;
    for (int i = 0; i < packages.size(); i++) {
      if (packages.at(i) > ideal_weight) {
        std::cout << "NO" << std::endl;
        skip = true;
        break;
      }
      for (int j = 0; j < dp.size(); j++) {
        if (dp.at(j) && packages.at(i) + j <= ideal_weight)
          dp.at(packages.at(i) + j) = true;
      }
      dp.at(packages.at(i)) = true;
    }
    if (!skip) {
      if (dp.at(ideal_weight))
        std::cout << "YES" << std::endl;
      else
        std::cout << "NO" << std::endl;
    }
  }
}
