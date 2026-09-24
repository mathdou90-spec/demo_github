#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N,M;
    cin>>N>>M;
    vector<pair<int,int>> intervals(M);
    for(int i=0;i<M;i++) {
        int a,b;
        cin>>a>>b;
        intervals[i] = {a,b-1};
    }
    sort(intervals.begin(),intervals.end(),
    [](const pair<int,int>& x,const pair<int,int>& y) {
        return x.second<y.second;
    });
    int count=0;
    int last_cut=-1;   //-1为更常见写法
    for(const auto& interval:intervals) {
        int l=interval.first;
        int r=interval.second;
        if(l>last_cut) {
            count++;
            last_cut=r;
        }
    }
    cout<<count<<endl;
}