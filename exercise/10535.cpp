#include <bits/stdc++.h>
using namespace std;

std::vector<long long> make_prime_num(long long n) {
  std::vector<bool> nums(n + 1, true);
  std::vector<long long> prime_num;
  prime_num.push_back(2);
  for (long long i = 3; i <= sqrt(n); i += 2)
    for (long long j = i * i; j <= n; j += i)
      nums.at(j) = false;
  for (long long i = 3; i <= n; i += 2)
    if (nums.at(i) == true)
      prime_num.push_back(i);
  return prime_num;
}

int main() {
  std::vector<long long> prime_num(make_prime_num(1000001));
  for (long long l, u; std::cin >> l >> u;) {
    int lidx = std::lower_bound(prime_num.begin(), prime_num.end(), l) -
               prime_num.begin();
    int hidx = std::upper_bound(prime_num.begin(), prime_num.end(), u) -
               prime_num.begin() - 1;
    if (lidx >= hidx)
      std::cout << "There are no adjacent primes." << std::endl;
    else {
      long long closest = std::numeric_limits<long long>::max(), most = -1;
      int closest_idx, most_idx;
      for (long long i = lidx; i + 1 <= hidx; i++) {
        if (prime_num.at(i + 1) - prime_num.at(i) < closest) {
          closest = prime_num.at(i + 1) - prime_num.at(i);
          closest_idx = i;
        }
        if (prime_num.at(i + 1) - prime_num.at(i) > most) {
          most = prime_num.at(i + 1) - prime_num.at(i);
          most_idx = i;
        }
      }
      std::cout << prime_num.at(closest_idx) << ","
                << prime_num.at(closest_idx + 1) << " are closest, "
                << prime_num.at(most_idx) << "," << prime_num.at(most_idx + 1)
                << " are most distant." << std::endl;
    }
  }
}
