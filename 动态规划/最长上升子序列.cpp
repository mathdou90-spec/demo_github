#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<int> dp(N,1);
    vector<int> a(N);
    for(int i=0;i<N;i++) {
        cin>>a[i];
    }
    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            if(a[j]<a[i]) {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int ans=dp[0];
    for(int i=1;i<N;i++) {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}