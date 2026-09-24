#include <vector>
#include <numeric>

template <typename T = int>
class DSU {
private:
    std::vector<T> parent;  // 父节点
    std::vector<int> rank;  // 秩(树的高度上界)
    int count_;             // 连通分量数量

public:
    // 构造函数:初始化 n 个元素
    explicit DSU(int n) : parent(n), rank(n, 0), count_(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    // 查找根节点(带路径压缩)
    T find(T x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // 路径压缩
        return parent[x];
    }

    // 合并两个集合(按秩合并),返回是否真的合并了
    bool unite(T x, T y) {
        T rx = find(x), ry = find(y);
        if (rx == ry) return false;

        // 按秩合并:把秩小的树挂到秩大的树下
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else if (rank[rx] > rank[ry]) {
            parent[ry] = rx;
        } else {
            parent[ry] = rx;
            rank[rx]++;  // 秩相等时,合并后秩 +1
        }
        count_--;
        return true;
    }

    // 判断两个元素是否在同一集合
    bool same(T x, T y) {
        return find(x) == find(y);
    }

    // 当前连通分量数量
    int count() const { return count_; }
};