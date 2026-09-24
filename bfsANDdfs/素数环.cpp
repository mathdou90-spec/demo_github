#include <cstring>
#include <cstdio>
using namespace std;

bool used[20];
bool isPrime[40];
int arr[20];
int n;

void intPrime() {
    for(int i=0;i<40;i++) isPrime[i]=true;
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<40;i++) {
        for(int j=i*i;j<40;j+=i) {
            isPrime[j]=false;
        }
    }
}

void dfs(int pos) {
    if(pos>n) {
        if(isPrime[arr[n]+arr[1]]) {
            printf("%d",arr[1]);
            for(int i=2;i<n;i++) {
                printf(" %d",arr[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i=2;i<=n;i++) {
        if(!used[i] && isPrime[arr[pos-1]+i]) {
            if(n%2==0) {
                if(pos%2==0 && i%2!=0) continue;
                if(pos%2!=0 && i%2==0) continue;
            }
            used[i]=true;
            arr[pos]=i;
            dfs(pos+1);
            used[i]=false;
        }
    }
}

int main() {
    intPrime();
    int caseno=1;
    while(scanf("%d",&n)!=EOF) {
        printf("Case %d:\n",caseno++);
        if(n==1) {
            printf("1\n");
        }
        else if(n%2==0) {
            memset(used,0,sizeof(used));
            arr[1]=1;
            used[1]=true;
            dfs(2);
        }
        printf("\n");
    }
    return 0;
}