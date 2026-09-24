#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);     //快速I/O
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        ll count=0;
        cin>>n;
        vector<ll> a(n);
        vector<ll> pref(n+1,0); 
        for(int i=0;i<n;i++) {
            cin>>a[i];
            pref[i+1]=pref[i]+a[i];    //前缀和,防止重复计算,使复杂度为o(n*n)
        }
        string s;
        cin>>s;
        int left=0,right=n-1;
        while(left<right) {
            while(left<right&&s[left]!='L') {
                left++;
            }
            while(left<right&&s[right]!='R') {
                right--;
            }
            if(left<right) {
                count+=pref[right+1]-pref[left];
            }
            left++;
            right--;
        }
        cout<<count<<"\n";   //用\n 代替 endl，防止频繁刷新缓冲区导致超时
    }
}