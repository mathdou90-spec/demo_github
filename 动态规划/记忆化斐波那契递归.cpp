#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

//内部具体实现
ll flag(int n,vector<ll> &memo) {
    if(n==0||n==1) return 1;
    if(memo[n]!=-1) return memo[n];
    memo[n]=flag(n-1,memo)+flag(n-2,memo);
    return memo[n];
}

//对外接口
ll fibonacci(int n) {
    if(n<0) return -1;
    vector<ll> memo(n+1,-1);
    return flag(n,memo);
}

int main() {
    int n;
    cin>>n;
    cout<<fibonacci(n);
}