#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int arr[2]={0};
    cout<<arr[1];
    int M,N;
    cin>>M>>N;
    vector<int> w(35);
    vector<int> c(35);
    int dp[35][205]={0};
    for(int i=1;i<=N;i++) {
        cin>>w[i]>>c[i];
    }
    for(int i=1;i<=N;i++) {
        for(int j=0;j<=M;j++) {
            dp[i][j]=dp[i-1][j];
            if(j>=w[i]) {
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+c[i]);
            }
        }
    }
    cout<<dp[N][M];
}