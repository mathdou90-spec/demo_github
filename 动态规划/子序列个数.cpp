#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution1 {
public:
    int numDistinct(string s, string t) {
        int m=t.size();
        int n=s.size();
        vector<vector<unsigned long long>> dp(m+1,vector<unsigned long long>(n+1,0));
        for(int j=0;j<=n;j++) {
            dp[0][j]=1;
        }
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(s[j-1]==t[i-1]) dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                else dp[i][j]=dp[i][j-1];
            }
        }
    return (int)dp[m][n];
    }
};
//滚动数组
class Solution2 {
public:
    int numDistinct(string s, string t) {
        int m=t.size();
        int n=s.size();
        vector<unsigned long long> dp(n+1,1);
        for(int i=1;i<=m;i++) {
            unsigned long long prev=dp[0];
            dp[0]=0;
            for(int j=1;j<=n;j++) {
                unsigned long long temp=dp[j];
                if(s[j-1]==t[i-1]) dp[j]=prev+dp[j-1];
                else dp[j]=dp[j-1];
                prev=temp;
            }
        }
        return (int)dp[n]; 
    }
};