#include <queue>
#include <vector>

std::vector<std::vector<int>> g;

// bfs that finds sizes of all pathes from src vertex to all reacheble
std::vector<int> bfs(int src) {
    int n = g.size();
    std::vector<int> d(n, -1);
    std::queue<int> q;
    d[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (d[to] == -1) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
    return d;
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
