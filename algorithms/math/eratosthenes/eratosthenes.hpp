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

}  // namespace classic_erat

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

}  // namespace linear_erat

namespace block_erat {

const int SQRT_N = 1e5;  // sqrt of input size
const int S = 1e4;       // size of block

std::array<bool, SQRT_N> nprime;
std::array<bool, S> bl;
std::array<int, SQRT_N> prime;
int cnt;

void build(int n) {
    int nsqrt = static_cast<int>(sqrtl(n));

    for (int i = 2; i <= nsqrt; ++i) {
        if (!nprime[i]) {
            prime[cnt++] = i;
            for (int j = i * i; j <= nsqrt; j += i) {
                nprime[j] = true;
            }
        }
    }

    for (int k = 0; k <= n / S; ++k) {
        bl.fill(false);
        int start = k * S;
        for (int i = 0; i < cnt; ++i) {
            int start_idx = (start + prime[i] - 1) / prime[i];
            int j = std::max(start_idx, 2) * prime[i] - start;
            for (; j < S; j += prime[i]) {
                bl[j] = true;
            }
        }
        if (k == 0) {
            bl[0] = bl[1] = true;
        }
        for (int i = 0; i < S && start + i <= n; ++i) {
            /*if bl[i] is false then start + i is prime*/
        }
    }
}

}  // namespace block_erat
