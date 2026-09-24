#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<ll> k(n),b(n);
    for(int i=0;i<n;i++) {
        cin >> k[i] >> b[i];
    }
    ll l=1,h=1e18;
    while(l<h) {       //终止条件
        ll mid=l+(h-l)/2;
        ll cut=0;
        for(int i=0;i<n;i++) {
            if(mid>=k[i]+b[i]) {
                ll add=(mid-b[i])/k[i];
                if(add>m-cut) add=m-cut;
                cut+=add;
                if(cut>=m) break;
            }
        }
        if(cut>=m) h=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
}