#include <vector>

std::vector<std::vector<int>> g;
std::vector<bool> used;

// simple dfs that calls itself from all ajacent nodes of current node
void dfs(int v) {
    /* your code here */

    used[v] = true;

    for (auto i : g[v]) {
        if (!used[i]) {
            dfs(i);
        }
    }
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

std::vector<std::vector<int>> table;
std::vector<std::vector<bool>> used_table;

// dfs for tables
void dfs(int i, int j) {
    used_table[i][j] = true;

    /* your code here */

    for (int x = -1; x < 2; ++x) {
        for (int y = -1; y < 2; ++y) {
            if (i + x >= 0 && i + x < (int)table.size() && j + y > 0 &&
                j + y < (int)table[0].size()) {
                if (!used_table[i + x][j + y]) {
                    dfs(i + x, j + y);
                }
            }
        }
    }
}

// r is count of rows and c is count of columns
void fill_table(int r, int c) {
    table.resize(r);
    used_table.resize(r);
    for (int i = 0; i < r; ++i) {
        used_table[i].assign(c, false);
        table[i].resize(c);
        for (int j = 0; j < c; ++j) {
            std::cin >> table[i][j];
        }
    }
}
