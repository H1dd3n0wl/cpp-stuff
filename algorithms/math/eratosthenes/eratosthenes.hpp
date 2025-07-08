#include <array>
#include <cmath>
#include <vector>

namespace classic_erat {
const int N = 1e7;

std::vector<bool> prime(N + 1, true);

void build() {
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        if (prime[i]) {
            for (int k = i * i; k <= N; k += i) {
                prime[k] = false;
            }
        }
    }
}

bool isPrime(int p) { return prime[p]; }

} // namespace classic_erat

namespace linear_erat {

const int N = 1e7;

std::array<int, N + 1> sieve;
std::array<int, N> pr;
int cnt = 0;

void build() {
    for (int i = 2; i <= N; ++i) {
        if (sieve[i] == 0) {
            sieve[i] = i;
            pr[cnt++] = i;
        }
        for (int j = 0; j < cnt && pr[j] <= sieve[i] && i * pr[j] <= N; ++j) {
            sieve[i * pr[j]] = pr[j];
        }
    }
}

inline bool isPrime(int p) { return sieve[p] == p; }

std::vector<int> factorize(int n) {
    std::vector<int> res;
    while (n != 1) {
        res.push_back(sieve[n]);
        n /= res.back();
    }
    return res;
}

} // namespace linear_erat
