#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve() {
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<ll> options;
    options.reserve(n);
    ll current_suffix_sum=0;
    for(int i=n-1;i>0;i--) {
        if(s[i]=='1') {
            current_suffix_sum++;
        }
        else {
            current_suffix_sum--;
        }
        options.push_back(current_suffix_sum);
    }
    sort(options.rbegin(),options.rend());
    int total_score_diff=0;
    int cuts=1;
    for(ll val:options) {
        if(val<=0) break;
        total_score_diff+=val;
        cuts++;
        if(total_score_diff>=k) {
            cout<<cuts<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if(cin>>t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}