#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAX=100005;
ll height[MAX];

int main() {
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0) {
        for(int i=0;i<n;i++) {
            scanf("%lld",&height[i]);
        }
        height[n]=0;
        stack<int> idx; 
        ll maxArea=0;
        for(int i=0;i<=n;i++) {
            while(!idx.empty()&&height[idx.top()]>height[i]) {
                ll h=height[idx.top()];
                idx.pop();
                int left=idx.empty()?-1:idx.top();
                ll w=i-left-1;
                maxArea=max(maxArea,h*w);
            }
            idx.push(i);
        }
        printf("%lld\n",maxArea);
    }
    return 0;
}