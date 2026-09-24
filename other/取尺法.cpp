#include  <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        string s;
        int K;
        cin>>s;
        cin>>K;
        int n=s.size();
        vector<int> freq(26,0);
        ll ans=0;
        int left=0;
        for(int right=0;right<n;right++) {
            int idx=s[right]-'a';
            freq[idx]++;
            while(freq[idx]>K) {
                freq[s[left]-'a']--;
                left++;
            }
            ans+=right-left+1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}