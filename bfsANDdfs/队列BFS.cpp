#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
const int MAXN=10000;
bool is_prime[MAXN];
int dist[MAXN];

void sieve() {                                //埃氏筛法选指质数
    fill(is_prime,is_prime+MAXN,true);
    is_prime[0]=is_prime[1]=false;
    for(int p=2;p*p<MAXN;p++) {
        if(is_prime[p]) {
            for(int i=p*p;i<MAXN;i+=p) {
                is_prime[i]=false;
            }
        }
    }
}
int bfs(int start,int target) {
    if(start==target) return 0;
    memset(dist,-1,sizeof(dist));
    queue<int> q;
    q.push(start);
    dist[start]=0;
    while(!q.empty()) {
        int curr=q.front();
        q.pop();                                //BFS
        if(curr==target) return dist[curr];
        int p10[4]={1,10,100,1000};
        for(int i=0;i<4;i++) {
            int currect_digit=(curr/p10[i])%10; //获取当前位
            int base=curr-(currect_digit*p10[i]);
            for(int j=0;j<=9;j++){
                int next_val=base+(j*p10[i]);
                if(next_val>=1000&&is_prime[next_val]&&dist[next_val]==-1) {
                    dist[next_val]=dist[curr]+1;
                    if(next_val==target) {
                        return dist[next_val];
                    }
                    q.push(next_val);
                }
            }
        }
    }
    return -1;
}

int main() {
    sieve();
    int A,B;
    while(cin>>A>>B) {
        int result=bfs(A,B);
        if(result==-1) {
            cout<<"-1"<<"\n";
        }
        else cout<<result<<"\n";
    }
}