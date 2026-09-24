#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXV=1005;
const int INF=0x3f3f3f3f; // 常用的无穷大，防止加法溢出

int n;
int w[MAXV][MAXV];
int dist[MAXV];//含义:从源点到当前节点的最近距离
int pre[MAXV];//前驱数组,用于回溯
bool used[MAXV];//标记是否已确定最短路径

void dijkstra(int s) {
    //初始化
    for(int i=0;i<n;i++) {
        dist[i]=INF;
        pre[i]=-1;
        used[i]=false;
    }
    dist[s]=0;
    for(int k=0;k<n;k++) {
        int u=-1;//先设为-1
        int MINDIST=INF;
        //先循环选出最小的点B
        for(int i=0;i<n;i++) {
            if(!used[i]&&dist[i]<MINDIST) {
                MINDIST=dist[i];
                u=i;
            }
        }
        if(u==-1||dist[u]==INF) break;
        used[u]=true;
        //松弛
        for(int v=0;v<n;v++) {
            if(!used[v]&&w[u][v]<INF&&w[u][v]+dist[u]<dist[v]) {
                dist[v]=dist[u]+w[u][v];
                pre[v]=u;
            }
        }
    }
}

void printPath(int s,int t) {
    if(s==t) {
        cout<<s;
        return;
    }
    if(pre[t]==-1) {
        cout<<"不可达";
        return;
    }
    //递归
    printPath(s,pre[t]);
    cout<<"->"<<t;
}
