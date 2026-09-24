#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct item{
    int w;
    int c;
};


int main() {
    int V,N,T;
    cin>>V>>N>>T;
    vector<item> group[11];
    int dp[201]={0};
    for(int i=1;i<=N;i++) {
        int w,c,p;
        cin>>w>>c>>p;
        group[p].push_back({w,c});
    }
    for(int i=1;i<=T;i++) {
        for(int j=V;j>=0;j--) {
            for(auto item:group[i]) {
                if(j>=item.w) dp[j]=max(dp[j],dp[j-item.w]+item.c);
            }
        }
    }
    cout<<dp[V]<<endl;
}