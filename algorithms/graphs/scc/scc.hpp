#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<std::vector<int>> g;
std::vector<std::vector<int>> r;

std::vector<bool> used;

std::vector<int> components;

std::vector<int> sorted;

void calc(int v) {
    used[v] = true;
    for (auto i : g[v]) {
        if (!used[i]) {
            calc(v);
        }
    }
    sorted.push_back(v);
}

void reverse_graph() {
    for (int i = 0; i < (int)g.size(); ++i) {
        for (auto j : g[i]) {
            r[j].push_back(i);
        }
    }
}

void dfs(int v, int pos) {
    used[v] = true;
    components[v] = pos;
    for (auto i : r[v]) {
        if (!used[i]) {
            dfs(v, pos);
        }
    }
}

void scc() {
    int pos = 0;
    for (int i = 0; i < (int)g.size(); ++i) {
        if (!used[i]) {
            calc(i);
        }
    }
    std::reverse(std::begin(sorted), std::end(sorted));
    used.assign(g.size(), false);
    for (auto i : sorted) {
        if (!used[i]) {
            pos++;
            dfs(i, pos);
        }
    }
}

void fill_graph(int n) {
    g.resize(n);
    r.resize(n);
    reverse_graph();
    used.assign(n, false);
    components.resize(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
    }
}

void print_comps() {
    int t = *std::max_element(std::begin(components), std::end(components));
    std::vector<std::vector<int>> c(t);
    for (int i = 0; i < (int)components.size(); ++i) {
        c[components[i] - 1].push_back(i + 1);
    }
    for (int i = 0; i < t; ++i) {
        std::cout << i << "th component:\n";
        std::copy(std::begin(c[i]), std::end(c[i]), std::ostream_iterator<int>{std::cout, " "});
        std::cout << '\n';
    }
}
