#include <bits/stdc++.h>
using namespace std;

const int maxn=100000;
const int maxq=100000;
int n,m;    //为查询次数
int a[maxn];
int block;

struct query{
    int l,r,id;
    bool operator<(const query &other) const {
        int b1=l/block,b2=other.l/block;
        if(b1!=b2) return b1<b2;
        return (b1&1)?(r<other.r):(r>other.r);
    }
}q[maxq];

int cut[maxn];
int curAns;
int ans[maxq];
//add和remove需要根据具体情况而修改
inline void add(int pos) {
    int val=a[pos];
    if(cut[val]==0) curAns++;
    cut[val]++;
}
inline void remove(int pos) {
    int val=a[pos];
    cut[val]--;
    if(cut[val]==0) curAns--;
}

void mo() {
    block=max(1,int(n/sqrt(m)));
    sort(q,q+m);
    int L=1;R=0;    //初始化为空
    curAns=0;
    for(int i=0;i<m;i++) {
        int ql=q[i].l,qr=q[i].r;
        while(L>ql) add(--L);
        while(R<qr) add(++R);
        while(L<ql) remove(L++);
        while(R>qr) remove(R--);
        ans[q[i].id]=curAns;  //id==i
    }
}