#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int N;
    cin>>N;
    vector<int> a(N);
    for(int i=0;i<N;i++) {
        cin>>a[i];
    }
    vector<int> dp(N);
    for(int i=1;i<N;i++) {
        if(i==0) dp[i]=a[i];
        if(dp[i]<0) dp[i]=0;
        if(i!=0) dp[i]=max(a[i],dp[i-1]+a[i]);
    }
    int result=*max_element(dp.begin(),dp.end());
    if(result<0) result=0;
    cout<<result<<endl;
}

int main() {
    int M;
    cin>>M;
    while(M--) solve();
}