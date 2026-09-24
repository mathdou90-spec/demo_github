#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXV = 1005;

// Kahn算法求拓扑排序
// 返回true表示成功（无环），false表示有环
bool topologicalSort(int n, const vector<vector<int>>& adj, vector<int>& order) {
    vector<int> indegree(n, 0);
    
    // 1. 统计入度 (P20代码逻辑)
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    // 2. 入度为0的节点入队 (P20代码逻辑)
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    order.clear();
    // 3. BFS处理 (P21代码逻辑)
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        // 遍历邻居，入度减1
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v); // 入度变0，加入队列
            }
        }
    }

    // 如果排出来的节点数不等于n，说明存在环 (P21: return count == g->n)
    return order.size() == n;
}