#include <iostream>
using namespace std;

int main() {
    int T,n;
    cin>>T;
    while(T--) {
        cin>>n;
        int arr[n];
        int total=0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            total+=arr[i];
        }
        if(total%2!=0) {
            cout<<"NO"<<endl;
            break;
        }
        int target=total/2;
        bool found=false;
        for(int mask=1;mask<(1<<n);mask++) {
            int sum=0;
            for(int i=0;i<n;i++) {
                if(mask&(1<<i)) {
                    sum+=arr[i];
                }
            }
            if(sum==target) {
                found=true;
            }
        }
        cout<<(found?"YES":"NO")<<endl;
    }
}