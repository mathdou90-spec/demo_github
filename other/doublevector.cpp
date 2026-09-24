#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,q;
    cin>>n>>q;
    vector<vector<int>> arr(n);
    while (q--) {
        int op;
        cin>>op;
        if(op==0) {
            int t,x;
            cin>>t>>x;
            arr[t].push_back(x);
        }
        else if(op==1) {
            int t;
            cin>>t;
            for(int i=0;i<arr[t].size();i++) {
                cout<<arr[t][i]<<" ";
            }
            cout<<endl;
        }
        else if(op==2) {
            int t;
            cin>>t;
            arr[t].clear();
        }
    }
}