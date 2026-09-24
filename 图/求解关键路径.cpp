#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// 定义边结构体
struct Edge {
    int to;     // 目标节点
    int w;      // 权值（活动持续时间）
};

/**
 * 关键路径算法
 * @param n 节点数量 (顶点编号 0 到 n-1)
 * @param adj 邻接表
 * @return 返回工程总工期T，若存在环则返回 -1
 */
int criticalPath(int n, const vector<vector<Edge>>& adj) {
    // 1. 统计入度
    vector<int> inDegree(n, 0);
    for (int u = 0; u < n; ++u) {
        for (const auto& e : adj[u]) {
            inDegree[e.to]++;
        }
    }

    // 2. 拓扑排序 + 正推计算 ve (最早发生时间)
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) q.push(i);
    }

    vector<int> topoOrder;
    vector<int> ve(n, 0); // 初始化为 0
    int count = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);
        count++;

        for (const auto& e : adj[u]) {
            // 更新目标节点的最早开始时间
            if (ve[u] + e.w > ve[e.to]) {
                ve[e.to] = ve[u] + e.w;
            }
            // 减少入度，入度为0时入队
            if (--inDegree[e.to] == 0) {
                q.push(e.to);
            }
        }
    }

    // 如果拓扑排序节点数小于总数，说明有环，不存在关键路径
    if (count < n) {
        cout << "图中存在环，无法计算关键路径！" << endl;
        return -1;
    }

    // 3. 计算总工期 T
    int T = 0;
    for (int i = 0; i < n; ++i) {
        T = max(T, ve[i]);
    }

    // 4. 逆拓扑序计算 vl (最晚发生时间)
    vector<int> vl(n, T); // 全部初始化为总工期 T
    for (int i = n - 1; i >= 0; --i) {
        int u = topoOrder[i];
        for (const auto& e : adj[u]) {
            // 更新当前节点的最晚发生时间
            if (vl[e.to] - e.w < vl[u]) {
                vl[u] = vl[e.to] - e.w;
            }
        }
    }

    // 5. 找出关键活动并输出
    cout << "关键活动路径如下：" << endl;
    for (int u = 0; u < n; ++u) {
        for (const auto& e : adj[u]) {
            int earliest = ve[u];              // 活动最早开始时间
            int latest = vl[e.to] - e.w;       // 活动最晚开始时间
            if (earliest == latest) {
                cout << "critical: " << u << " -> " << e.to 
                     << " (权重: " << e.w << ")" << endl;
            }
        }
    }

    return T;
}

// 测试代码
int main() {
    /*
     * 示例图:
     * 0 -> 1 (权重 3)
     * 0 -> 2 (权重 2)
     * 1 -> 3 (权重 2)
     * 2 -> 3 (权重 4)
     * 3 -> 4 (权重 3)
     */
    int n = 5;
    vector<vector<Edge>> adj(n);
    
    adj[0].push_back({1, 3});
    adj[0].push_back({2, 2});
    adj[1].push_back({3, 2});
    adj[2].push_back({3, 4});
    adj[3].push_back({4, 3});

    int totalDuration = criticalPath(n, adj);
    
    if (totalDuration != -1) {
        cout << "工程总工期 T = " << totalDuration << endl;
    }

    return 0;
}