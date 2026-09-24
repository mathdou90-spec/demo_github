#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXV = 1005;
const int INF = 0x3f3f3f3f; // 常用的无穷大，防止加法溢出

int n; // 顶点数
int w[MAXV][MAXV]; // 邻接矩阵
int dist[MAXV]; // 距离数组
int pre[MAXV];  // 前驱节点数组
bool used[MAXV]; // 标记是否已确定最短路径

// 按照图片P7、P8的代码逻辑整理
void dijkstra(int s) {
    // 1. 初始化
    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
        pre[i] = -1;
        used[i] = false;
    }
    dist[s] = 0;

    // 2. 循环 n 次
    for (int k = 0; k < n; ++k) {
        // 选点：寻找未确定的点中 dist 最小的
        int u = -1;
        int minDist = INF;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        // 如果找不到（u == -1）或者剩余点不可达（dist[u] == INF），提前结束
        if (u == -1 || dist[u] == INF) break;

        // 锁定该点
        used[u] = true;

        // 3. 松弛操作：用 u 更新其邻居 v
        for (int v = 0; v < n; ++v) {
            // 如果 v 未锁定，且 u 到 v 有边，且经过 u 到 v 的距离更短
            if (!used[v] && w[u][v] < INF) {
                if (dist[u] + w[u][v] < dist[v]) {
                    dist[v] = dist[u] + w[u][v];
                    pre[v] = u; // 记录前驱
                }
            }
        }
    }
}

// 辅助函数：打印路径
void printPath(int s, int t) {
    if (t == s) {
        cout << s;
        return;
    }
    if (pre[t] == -1) {
        cout << "不可达";
        return;
    }
    printPath(s, pre[t]);
    cout << " -> " << t;
}

int main() {
    // 示例初始化
    n = 6;
    // 初始化邻接矩阵为 INF
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            w[i][j] = (i == j) ? 0 : INF;

    // 添加边 (模拟图片中的图: A=0, B=1, C=2, D=3, E=4, F=5)
    w[0][1] = 2; w[1][0] = 2; // A-B
    w[0][5] = 3; w[5][0] = 3; // A-F
    w[1][2] = 3; w[2][1] = 3; // B-C
    w[1][4] = 5; w[4][1] = 5; // B-E
    w[2][3] = 2; w[3][2] = 2; // C-D
    w[2][4] = 6; w[4][2] = 6; // C-E
    w[3][4] = 4; w[4][3] = 4; // D-E
    w[4][5] = 2; w[5][4] = 2; // E-F

    int s = 0; // 假设源点为 A
    dijkstra(s);

    cout << "从源点 " << s << " 到各点的最短距离：" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "到点 " << i << " 的距离: ";
        if (dist[i] == INF) cout << "INF";
        else cout << dist[i];
        cout << " | 路径: ";
        printPath(s, i);
        cout << endl;
    }
    return 0;
}