//八码数问题
#include <iostream>
#include <vector>
using namespace std;

int n = 5;
vector<vector<int>> maze = {
    {0,0,0,0,0},
    {1,1,0,1,0},
    {0,0,0,1,0},
    {0,1,0,0,0},
    {0,1,0,1,0}
};
int sx = 0, sy = 0, ex = 4, ey = 4;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

// 深度限制搜索：当前(x,y)，步数step，深度限制limit，访问数组vis，路径path
bool DLS(int x, int y, int step, int limit, 
         vector<vector<bool>>& vis, vector<pair<int,int>>& path) {
    if (step > limit) return false;
    if (x == ex && y == ey) {
        path.push_back({x, y});
        return true;
    }
    vis[x][y] = true;
    path.push_back({x, y});

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx<0||nx>=n||ny<0||ny>=n) continue;
        if (maze[nx][ny]==1 || vis[nx][ny]) continue;
        if (DLS(nx, ny, step+1, limit, vis, path))
            return true;
    }

    // 回溯
    path.pop_back();
    vis[x][y] = false;
    return false;
}

int main() {
    int maxDepth = n * n;  // 理论上界
    for (int depth = 0; depth <= maxDepth; depth++) {
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<pair<int,int>> path;
        if (DLS(sx, sy, 0, depth, vis, path)) {
            cout << "最短步数: " << depth << endl;
            cout << "路径: ";
            for (auto p : path) cout << "(" << p.first << "," << p.second << ") ";
            cout << endl;
            break;
        }
    }
    return 0;
}