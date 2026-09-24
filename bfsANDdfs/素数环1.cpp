#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool used[25];
int arr[25];
int n;

bool isPrime(int n) {
    if(n<2) return false;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) return false;
    }
    return true;
}

void dfs(int pos) {
    if(pos>n) {
        if(isPrime(arr[n]+arr[1])) {
            cout<<arr[1];
            for(int i=2;i<n;i++) {
                cout<<" "<<arr[i];
            }
            cout<<endl;
        }
        return;
    }
    for(int i=2;i<=n;i++) {
        if(!used[i] && isPrime(arr[pos-1]+i)) {
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
    cin>>n;
    if(n==1) cout<<"1"<<endl;
    else if(n%2==0) {
        memset(used,0,sizeof(used));
        arr[1]=1;
        used[1]=true;
        dfs(2);
    }
    return 0;
}