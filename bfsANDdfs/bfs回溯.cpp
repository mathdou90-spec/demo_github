#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 5;
int maze[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs() {
    queue<pair<int, int>> q;
    maze[0][0] = 10;           // 起点标记为 10
    q.push({0, 0});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == N - 1 && y == N - 1) return;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N
                && maze[nx][ny] == 0) {           // 只扩展原始的路
                maze[nx][ny] = maze[x][y] + 1;   // 正确递增
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>maze[i][j];
        }
    }

    bfs();

    vector<pair<int, int>> path;
    int x = N - 1, y = N - 1;
    path.push_back({x, y});
    while (maze[x][y] != 10) {                  // 回到起点标志 10
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N
                && maze[nx][ny] == maze[x][y] - 1) {
                x = nx; y = ny;
                path.push_back({x, y});
                break;
            }
        }
    }

    for (int i = path.size() - 1; i >= 0; --i) {
        cout << "(" << path[i].first << ", " << path[i].second << ")\n";
    }

    return 0;
}