#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool check(int x,vector<int>& arr) {
    int prev=INT_MIN;
    for(int a:arr) {
        int l=a-x;
        int h=a+x;
        int need=prev+1;
        int choose=max(l,need);
        if(choose>h) return false;
        prev=choose;
    }
    return true;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i=0;i<N;i++) {
            cin>>arr[i];
        }
        int begin=0,end=2000000,ans=end;
        while(begin<=end) {
            int mid=begin+(end-begin)/2;
            if(check(mid,arr)) {
                ans=mid;
                end=mid-1;
            } else {
                begin=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}