#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXV = 1005;
const int INF = 0x3f3f3f3f; // 常用无穷大

int n; // 顶点数

// 核心Prim算法 (对应图片P16, P17的代码)
// 返回1表示成功，0表示图不连通
int prim(int w[MAXV][MAXV], int s, long long *total) {
    int key[MAXV];
    int used[MAXV] = {0}; // 标记是否已被拉入生成树

    // 1. 初始化
    for (int i = 0; i < n; ++i) {
        key[i] = INF;
    }
    key[s] = 0;   // 起点接入成本为0
    *total = 0;   // 总权值清零

    // 2. 循环 n 次，寻找 n 个点
    for (int k = 0; k < n; ++k) {
        int u = -1;
        int minKey = INF;

        // 【选点】寻找未被使用且 key 最小的点
        for (int i = 0; i < n; ++i) {
            if (!used[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        // 如果找不到 (u == -1) 或者剩余点不可达 (key[u] == INF)
        // 说明图不连通 (对应图片P17底部的备注)
        if (u == -1 || key[u] == INF) return 0;

        // 【锁定】标记为已使用
        used[u] = 1;
        // 【累加】加上接入成本 (对应P17手写笔记“松弛”前面的逻辑)
        *total += key[u];

        // 【松弛】更新邻居节点的 key 值
        for (int v = 0; v < n; ++v) {
            // 核心区别！这里是直接用 w[u][v] 与 key[v] 比较，而不是累加！
            if (!used[v] && w[u][v] < INF && w[u][v] < key[v]) {
                key[v] = w[u][v]; 
            }
        }
    }
    return 1; // 成功构建最小生成树
}

int main() {
    // 测试用例（参考P15的图 A=0, B=1, C=2, D=3, E=4, F=5）
    n = 6;
    int w[MAXV][MAXV];

    // 初始化邻接矩阵
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            w[i][j] = (i == j) ? 0 : INF;

    // 添加边（无向图，双向赋值）
    auto addEdge = [&](int u, int v, int weight) {
        w[u][v] = min(w[u][v], weight);
        w[v][u] = min(w[v][u], weight);
    };

    addEdge(0, 1, 2); // A-B
    addEdge(0, 5, 3); // A-F
    addEdge(1, 2, 3); // B-C
    addEdge(1, 4, 5); // B-E
    addEdge(2, 3, 2); // C-D
    addEdge(2, 4, 6); // C-E
    addEdge(3, 4, 4); // D-E
    addEdge(4, 5, 2); // E-F

    long long totalWeight = 0;
    int s = 4; // 假设从 E 点 (索引4) 开始

    if (prim(w, s, &totalWeight)) {
        cout << "从点 " << s << " 开始构建的最小生成树总权值: " << totalWeight << endl;
    } else {
        cout << "图不连通，无法生成最小生成树！" << endl;
    }

    return 0;
}