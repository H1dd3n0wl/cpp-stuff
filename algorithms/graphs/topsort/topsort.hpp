#include <vector>
#include <algorithm>

std::vector<std::vector<int>> g;
std::vector<bool> used;
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
    used.assign(g.size(), false);
    ans.clear();
    for (int i = 0; i < (int)g.size(); ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    std::reverse(std::begin(ans), std::end(ans));
}

// n is count of vertexes and m is count of edges
void fill_graph(int n, int m) {
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;
        g[l].push_back(r);
        g[r].push_back(l);
    }
}