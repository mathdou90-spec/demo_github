#include <iostream>
using namespace std;

const int MAXN=50010;
int N,K;
int parent[MAXN];
int relation[MAXN];
void init(int N) {
    for(int i=1;i<=N;i++) {
        parent[i]=i;
        relation[i]=0;
    }
}

int find(int x) {
    if(parent[x]!=x) {
        int original_parent=parent[x];
        parent[x]=find(parent[x]);
        relation[x]=(relation[x]+relation[original_parent])%3;
    }
    return parent[x];
}

bool merge(int x,int y,int d) {
    if(x>N||y>N) return false;
    if(d==2&&x==y) return false;
    int rx=find(x),ry=find(y);
    if(rx==ry) {
        if((relation[x]-relation[y]+3)%3!=d-1) return false;
        return true;
    }
    else {
        parent[rx]=ry;
        relation[rx]=(d-1+relation[y]-relation[x]+3)%3;
        return true;
    }
}
int main() {
    cin>>N>>K;
    init(N);
    int nums=0;
    while(K--) {
        int d,x,y;
        cin>>d>>x>>y;
        if(!merge(x,y,d)) nums++;
    }
    cout<<nums<<endl;
    return 0;
}