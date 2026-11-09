
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<char>> maze;
vector<vector<bool>> visited;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y) {
    if (maze[x][y] == 'E') {
        return 0;
    }

    visited[x][y] = true;

    int best = -1000000;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
            maze[nx][ny] != '1' && !visited[nx][ny]) {

            int result = dfs(nx, ny);

            if (result != -1000000) {
                best = max(best, result);
            }
        }
    }

    visited[x][y] = false;

    if (best == -1000000) {
        return -1000000;
    }

    return best + (maze[x][y] == 'P' ? 1 : 0);
}

int main() {
    cin >> n >> m;

    maze.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    int sx = -1, sy = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];

            if (maze[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }

    cout << dfs(sx, sy) << endl;

    return 0;
}
