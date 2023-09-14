#include <vector>

const int N = 1e7;

std::vector<int> sieve(N);

void build() {
    for (int i = 0; i < N; ++i) {
        sieve[i] = i;
    }

    for (int i = 2; i * i <= N; ++i) {
        if (sieve[i] == i) {
            for (int k = i * i; k < N; k += i) {
                sieve[k] = i;
            }
        }
    }
}


inline bool isPrime(int p) {
    return sieve[p] == p;
}

std::vector<int> factorize(int n) {
    std::vector<int> res;
    while (n != 1) {
        res.push_back(sieve[n]);
        n /= res.back();
    }
    return res;
}