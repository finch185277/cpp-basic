#include <bits/stdc++.h>

std::string big_nums_add(std::string &s1, std::string &s2) {
  std::string ret;
  int carry = 0;
  int i = s1.size() - 1, j = s2.size() - 1;
  while (i >= 0 || j >= 0) {
    int n1 = i >= 0 ? s1[i--] - '0' : 0;
    int n2 = j >= 0 ? s2[j--] - '0' : 0;
    int cur = n1 + n2 + carry;
    ret = std::to_string(cur % 10) + ret;
    carry = cur / 10;
  }
  if (carry > 0)
    ret = std::to_string(carry) + ret;
  return ret;
}

std::string big_nums_mul(std::string &s1, std::string &s2) {
  std::string ret;
  int carry = 0;
  std::vector<int> raw_sum(s1.size() + s2.size() - 1);
  for (int i = 0; i < s1.size(); i++)
    for (int j = 0; j < s2.size(); j++)
      raw_sum.at(i + j) += (s1[i] - '0') * (s2[j] - '0');
  for (int k = raw_sum.size() - 1; k >= 0; k--) {
    int cur = raw_sum.at(k) + carry;
    ret = std::to_string(cur % 10) + ret;
    carry = cur / 10;
  }
  if (carry > 0)
    ret = std::to_string(carry) + ret;
  return ret;
}

int main() {
  std::string num;
  std::vector<std::string> nums;
  while (std::cin >> num)
    nums.push_back(num);
  std::string add_sum = nums.front(), mul_sum = nums.front();
  for (int i = 1; i < nums.size(); i++) {
    add_sum = big_nums_add(add_sum, nums.at(i));
    mul_sum = big_nums_mul(mul_sum, nums.at(i));
  }
  std::cout << "nums =";
  for (std::string &num : nums)
    std::cout << ' ' << num;
  std::cout << std::endl;
  std::cout << "Big nums add: " << add_sum << std::endl;
  std::cout << "Big nums mul: " << mul_sum << std::endl;
}
