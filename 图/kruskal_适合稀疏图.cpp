#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXV = 1005;

// 边结构体定义（对应P14的Edge）
struct Edge {
    int from, to;
    long long weight; // 允许负权，使用 long long 防溢出
};

// 并查集数组（对应P13）
int parent[MAXV];
int sz[MAXV]; // 注意，图片里的 size 容易和 std::size 冲突，这里改名为 sz

// 路径压缩（对应P13的 findSet）
int findSet(int x) {
    if (parent[x] != x) {
        parent[x] = findSet(parent[x]); // 递归查找并压缩路径
    }
    return parent[x];
}

// 按大小合并（对应P13的 unite）
void unite(int a, int b) {
    int rootA = findSet(a);
    int rootB = findSet(b);
    if (rootA == rootB) return;
    
    // 小树合并到大树，保证树高更小
    if (sz[rootA] < sz[rootB]) {
        swap(rootA, rootB);
    }
    parent[rootB] = rootA;
    sz[rootA] += sz[rootB];
}

// 比较器：从小到大排序（对应P13的 cmp）
bool cmp(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

// Kruskal核心算法（对应P14的 kruskal）
bool kruskal(int n, vector<Edge>& edges, long long &totalWeight) {
    // 1. 初始化并查集
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
    
    // 2. 边权从小到大排序 O(m log m)
    sort(edges.begin(), edges.end(), cmp);
    
    int count = 0; // 记录已加入生成树的边数
    totalWeight = 0;
    
    // 3. 遍历选边
    for (size_t i = 0; i < edges.size() && count < n - 1; ++i) {
        int a = findSet(edges[i].from);
        int b = findSet(edges[i].to);
        
        // 核心判断：如果不在同一连通块，则加边；否则跳过（防成环）
        if (a != b) {
            unite(a, b);
            totalWeight += edges[i].weight;
            count++;
        }
    }
    
    // 4. 成功条件：恰好选出了 n-1 条边
    return count == n - 1;
}

// 测试用例
int main() {
    int n = 6; // 假设有6个点 (A=0, B=1, C=2, D=3, E=4, F=5)
    vector<Edge> edges;
    
    // 添加边（参考图片P11中的图）
    edges.push_back({0, 1, 2}); // A-B
    edges.push_back({0, 5, 3}); // A-F
    edges.push_back({1, 2, 3}); // B-C
    edges.push_back({1, 4, 5}); // B-E
    edges.push_back({2, 3, 2}); // C-D
    edges.push_back({2, 4, 6}); // C-E
    edges.push_back({3, 4, 4}); // D-E
    edges.push_back({4, 5, 2}); // E-F

    long long totalWeight = 0;
    if (kruskal(n, edges, totalWeight)) {
        cout << "最小生成树的总权值为: " << totalWeight << endl;
    } else {
        cout << "图不连通，无法生成最小生成树！" << endl;
    }

    return 0;
}