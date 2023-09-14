#include <vector>

class FenwickTree {
private:
    int n;
    std::vector<long long> t;

public:

    inline void add(int v, long long delta) {
        for (; v < n; v |= v + 1) {
            t[v] += delta;
        }
    }

    inline long long sum(int v) {
        long long res = 0;
        for (v; v >= 0; v &= v+1, v--) {
            res += t[v];
        }
        return res;
    }

    inline long long sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    FenwickTree(int n) : n{n}, t(n, 0) {}
};
