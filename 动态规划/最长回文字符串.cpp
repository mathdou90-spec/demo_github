#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<2) return s;
        vector<bool> dp(n,false);
        int start=0,maxlen=1;
        for(int i=n-1;i>=0;i--) {
            for(int j=n-1;j>=i;j--) {
                if(i==j) dp[j]=true;
                else if(s[i]==s[j]) {
                    dp[j]=(j-i<=2)||dp[j-1];
                }
                else dp[j]=false;
                if(dp[j]&&j-i+1>maxlen) {
                    start=i;
                    maxlen=j-i+1;
                }
            }
        }
        return s.substr(start,maxlen);
    }
};