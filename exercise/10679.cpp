#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

std::vector<unsigned int> make_prime_num(unsigned int n) {
  std::vector<bool> num(n, true);
  std::vector<unsigned int> prime_num;
  prime_num.push_back(2);
  for (int i = 3; i < sqrt(n); i += 2) {
    if (num.at(i)) {
      for (int j = i * i; j < n; j += i)
        num.at(j) = false;
    }
  }
  for (int i = 3; i < n; i += 2)
    if (num.at(i))
      prime_num.push_back(i);
  return prime_num;
}

int main() {
  std::vector<unsigned int> prime_num(make_prime_num(10000000));
  for (unsigned int n; std::cin >> n && n != 0;) {
    unsigned int ret = n;
    std::vector<int> factor;
    for (int i = 0; i < prime_num.size(); i++) {
      if (prime_num.at(i) > n)
        break;
      if (n % prime_num.at(i) == 0)
        factor.push_back(prime_num.at(i));
      while (n % prime_num.at(i) == 0) {
        n /= prime_num.at(i);
      }
    }
    for (int i = 0; i < factor.size(); i++) {
      ret = ret / factor.at(i) * (factor.at(i) - 1);
    }
    std::cout << ret << std::endl;
  }
}
