#include <iostream>
using namespace std;

const int N = 5;

int maze[N][N] = {
    {1,0,1,0,1},
    {1,1,1,1,1},
    {0,1,0,1,1},
    {1,0,0,1,1},
    {1,1,1,0,1}
};

int sol[N][N] = {0};
bool vis[N][N] = {0};

bool ok(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N && maze[r][c] == 1 && !vis[r][c];
}

bool dfs(int r, int c) {
    if (!ok(r, c)) return false;
    vis[r][c] = true;
    sol[r][c] = 1;
    if (r == N - 1 && c == N - 1) return true;
    if (dfs(r, c + 1)) return true;
    if (dfs(r + 1, c)) return true;
    if (dfs(r, c - 1)) return true;
    if (dfs(r - 1, c)) return true;
    sol[r][c] = 0;
    return false;
}

int main() {
    if (maze[0][0] == 1 && maze[N - 1][N - 1] == 1 && dfs(0, 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << sol[i][j] << (j + 1 == N ? '\n' : ' ');
            }
        }
    } else {
        cout << "No path found\n";
    }
    return 0;
}
