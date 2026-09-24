#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool check(int x,vector<int> &A) {
    //第一个A不用不任何人大
    int prev=INT_MIN;
    for(int a:A) {
        int low=a-x;
        int high=a+x;
        //后一个数至少比前一个大一
        int need=prev+1;
        int choose=max(low,need);
        if(choose>high) return false;
        //prev用于记录上一个B的值
        prev=choose;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++) {
            cin>>A[i];
        }
        int low=0;
        int high=2000000;
        int ans=high;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(check(mid,A)) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        cout<<"Case #"<<t<<":\n";
        cout<<ans<<"\n";
    }
}