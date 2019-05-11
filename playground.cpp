#include <bits/stdc++.h>
using namespace std;

std::string big_num_add(std::string &s1, std::string &s2) {
  std::string ret;
  int i = s1.size() - 1, j = s2.size() - 1, carry = 0;
  for (; i >= 0 || j >= 0;) {
    int n1 = i >= 0 ? s1[i--] - '0' : 0;
    int n2 = j >= 0 ? s2[j--] - '0' : 0;
    int sum = n1 + n2 + carry;
    ret = std::to_string(sum % 10) + ret;
    carry = sum / 10;
  }
  if (carry > 0) {
    ret = std::to_string(carry) + ret;
  }
  return ret;
}
std::string big_num_mul(std::string &s1, std::string &s2) {
  std::string ret;
  std::vector<int> sum_vec(s1.size() + s2.size() - 1);
  for (int i = 0; i < s1.size(); i++) {
    for (int j = 0; j < s2.size(); j++) {
      sum_vec.at(i + j) += (s1[i] - '0') * (s2[j] - '0');
    }
  }
  int carry = 0;
  for (int k = sum_vec.size() - 1; k >= 0; k--) {
    ret = std::to_string((sum_vec.at(k) + carry) % 10) + ret;
    carry = (sum_vec.at(k) + carry) / 10;
  }
  if (carry > 0)
    ret = std::to_string(carry) + ret;
  return ret;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string s1, s2;
  std::cin >> s1 >> s2;
  std::cout << big_num_add(s1, s2) << std::endl;
  std::cout << big_num_mul(s1, s2) << std::endl;
}
