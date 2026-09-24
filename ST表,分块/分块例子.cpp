#include<bits/stdc++.h>
#include <cmath>
using namespace std;
int n,len,a[10000],b[10000],addv[10000];  //b[i]用于记录i属于那一块,addv建议初始化为零
vector<int> v[10000];
//对x块排序
void Sort(int x) {
    v[x].clear();
    for(int i=(x-1)*len+1;i<=min(x*len,n);i++) {
        v[x].push_back(a[i]);
    }
    sort(v[x].begin(),v[x].end());
}
//修改
void modify(int l,int r,int c) {
    for(int i=l;i<=min(b[l]*len,r);i++) {
        a[i]+=c;
    }
    Sort(b[l]);
    if(b[l]!=b[r]) {
        for(int i=(b[r]-1)*len+1;i<=r;i++) {
            a[i]+=c;
        }
        Sort(b[r]);
    }
    for(int i=b[l]+1;i<b[r];i++) {
        addv[i]+=c;
    }
}
//查询
void query(int l,int r,int c) {
    int ans=0;  //统计个数
    for(int i=l;i<=min(b[l]*len,r);i++) {
        if(a[i]+addv[b[l]]<c) ans++;
    }
    if(b[l]!=b[r]) {
        for(int i=(b[r]-1)*len+1;i<=r;i++) {
            if(a[i]+addv[b[r]]<c) ans++;
        }
    }
    for(int i=b[l]+1;i<b[r];i++) {
        int tag=c-addv[i];
        ans+=lower_bound(v[i].begin(),v[i].end(),tag)-v[i].begin();
    }
    cout<<ans<<endl;
}

int main() {
    len=sqrt(n);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        b[i]=(i-1)/len+1;
        v[b[i]].push_back(a[i]);
    }
    for(int i=1;i<=b[n];i++) {
        sort(v[i].begin(),v[i].end());
    }
}