//本程序实际上就是二分
#include <bits/stdc++.h>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length(),n=p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int j=1;j<=n;j++) {
            if(p[j-1]=='*') dp[0][j]=dp[0][j-2];
        }
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(p[j-1]=='*') {
                    dp[i][j]=dp[i][j-2];
                    if(p[j-2]=='.'||p[j-2]==s[i-1]) {
                        dp[i][j] = (dp[i][j]||dp[i-1][j]);
                    }
                } else {
                    bool first_match=(p[j-1]=='.'||p[j-1]==s[i-1]);
                    dp[i][j]=first_match&&dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};