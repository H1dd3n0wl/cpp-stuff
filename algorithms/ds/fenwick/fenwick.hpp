#include <array>

template <std::size_t N>
class FenwickTree {
private:
    std::array<long long, N> t_;

public:
    inline void add(int v, long long delta) {
        for (; v < N; v |= v + 1) {
            t_[v] += delta;
        }
    }

    inline long long sum(int v) {
        long long res = 0;
        for (v; v >= 0; v &= v + 1, v--) {
            res += t_[v];
        }
        return res;
    }

    inline long long sum(int l, int r) { return sum(r) - sum(l - 1); }

    FenwickTree(std::array<long long, N> t) {
        for (std::size_t i = 0; i < N; ++i) {
            add(i, t[i]);
        }
    }

    FenwickTree() {
        t_.fill(0);
    }
};
