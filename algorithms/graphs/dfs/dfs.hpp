#include <vector>

const int MAX_N = 1e5 + 5;

std::vector<std::vector<int>> g(MAX_N);
std::vector<bool> used(MAX_N, false);

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


const int ROWS = 1e3;
const int COLS = 1e3;

std::vector<std::vector<int>> table(ROWS, std::vector<int>(COLS));
std::vector<std::vector<bool>> used_table(ROWS, std::vector<bool>(COLS, false));

// dfs for tables
void dfs(int i, int j) {
    used_table[i][j] = true;

    /* your code here */

    for (int x = -1; x < 2; ++x) {
        for (int y = -1; y < 2; ++y) {
            if (i + x >= 0 && i + x < ROWS && j + y > 0 && j + y < COLS) {
                if (!used_table[i + x][j + y]) {
                    dfs(i + x, j + y);
                }
            }
        }
    }
}

