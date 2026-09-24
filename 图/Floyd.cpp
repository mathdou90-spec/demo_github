#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXV = 1005;
const int INF = 0x3f3f3f3f; // 常用无穷大，防溢出

int n; // 节点数
int dist[MAXV][MAXV]; // 距离矩阵

void floyd() {
    // 核心三重循环
    // 1. 外层循环 k：枚举中转站（DP阶段）
    for (int k = 0; k < n; ++k) {
        // 2. 中间层循环 i：枚举起点
        for (int i = 0; i < n; ++i) {
            // 3. 内层循环 j：枚举终点
            for (int j = 0; j < n; ++j) {
                // 如果经过 k 不能到达，直接跳过（避免 INF + 正数溢出）
                if (dist[i][k] == INF || dist[k][j] == INF) continue;
                
                // 状态转移方程：尝试用 k 作为中转站来松弛 i -> j 的路径
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    // 示例：初始化矩阵
    // 读入 n 和边，通常在此处处理
    // 初始化 dist 矩阵：
    // 对角线 dist[i][i] = 0，无边的 dist[i][j] = INF
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    // 假设输入边 (u, v, w)
    // dist[u][v] = min(dist[u][v], w); // 若有多重边取最小
    // 注意：如果是无向图，需双向赋值 dist[u][v] = dist[v][u] = w;

    // 调用算法
    floyd();

    // 输出结果
    cout << "任意两点间最短路径矩阵：" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) cout << "INF\t";
            else cout << dist[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}