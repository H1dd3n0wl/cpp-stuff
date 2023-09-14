#include <vector>

const int MAXN = 1e5 + 5;
int n;
std::vector<std::vector<int>> g(MAXN, std::vector<int>(MAXN));
std::vector<bool> used(MAXN, false);
std::vector<int> ans;

void dfs(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    ans.push_back(v);
}

void topological_sort() {
    used.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    std::reverse(std::begin(ans), std::end(ans));
}