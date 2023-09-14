#include <vector>
#include <queue>


//bfs that finds sizes of all pathes from src vertex to all reacheble
std::vector<int> bfs(std::vector<std::vector<int>> g, int src) {
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

