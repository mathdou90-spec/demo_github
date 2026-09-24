#include <cmath>
#include <iostream>
using namespace std;

#define maxn 1000
int f[maxn][21],a[maxn];

void init(int n) {
    for(int i=1;i<=n;i++) f[i][0]=a[i];
    for(int j=1;j<=log2(n);j++) {
        for(int i=1;i+((1<<j)-1);i++) {
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r) {
    int j=log2(r-l+1);
    return max(f[l][j],f[r-(1<<j)+1][r]);
}