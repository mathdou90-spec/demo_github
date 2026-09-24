#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string tentotwo(int n) {
    if(n==1) return"1";
    if(n==0) return"0";
    return tentotwo(n/2)+(n%2?"1":"0");
}
int main() {
    int n;
    cin>>n;
    while(n>0) {
        n--;
        int ten_num;
        cin>>ten_num;
        string a=tentotwo(ten_num);
        string b=a;
        reverse(a.begin(),a.end());
        cout<<a<<b;
        if(a==b) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
}
