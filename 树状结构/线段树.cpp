#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;          

#define ls (rt << 1) 
#define rs (rt << 1 | 1)      

int a[maxn];                      
class MySegTree {
private:
    struct SegTree {
        int l, r, sum, lazy;
    } T[maxn << 2];

    void pushup(int rt) {        
        T[rt].sum = T[ls].sum + T[rs].sum;
    }

    void pushdown(int rt) {       
        if (T[rt].lazy) {
            T[ls].sum += (T[ls].r - T[ls].l + 1) * T[rt].lazy;
            T[rs].sum += (T[rs].r - T[rs].l + 1) * T[rt].lazy; 
            T[ls].lazy += T[rt].lazy;
            T[rs].lazy += T[rt].lazy;
            T[rt].lazy = 0;
        }
    }

    void build(int l, int r, int rt) {
        T[rt].l = l, T[rt].r = r;
        T[rt].sum = 0;
        T[rt].lazy = 0;           
        if (l == r) {
            T[rt].sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, ls);
        build(mid + 1, r, rs);
        pushup(rt);
    }

public:                          
    MySegTree(int n) {           
        build(1, n, 1);
    }

    void add(int pos, int val, int rt = 1) {
        if (T[rt].l == T[rt].r && T[rt].l == pos) {
            T[rt].sum += val;
            return;
        }
        pushdown(rt);           
        int mid = (T[rt].l + T[rt].r) >> 1;
        if (pos <= mid) add(pos, val, ls);
        else add(pos, val, rs);
        pushup(rt);
    }

    int query(int l, int r, int rt = 1) {
        if (l <= T[rt].l && r >= T[rt].r)
            return T[rt].sum;
        pushdown(rt);            
        int mid = (T[rt].l + T[rt].r) >> 1;
        int ans = 0;
        if (l <= mid) ans += query(l, r, ls);
        if (r > mid)  ans += query(l, r, rs); 
        return ans;
    }

    void update(int l, int r, int rt, long long val) {
        if (l <= T[rt].l && r >= T[rt].r) {
            T[rt].sum += (T[rt].r - T[rt].l + 1) * val;
            T[rt].lazy += val;
            return;
        }
        pushdown(rt);
        int mid = (T[rt].l + T[rt].r) >> 1;
        if (l <= mid) update(l, r, ls, val);
        if (r > mid)  update(l, r, rs, val); 
        pushup(rt);
    }
};