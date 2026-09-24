#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,m;//m行n列
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int u=1;u<=n;u++) {
        cout<<u<<":";
        for(int v:g[u]) {
            cout<<" "<<v;
        }
        cout<<"\n";
    }
}