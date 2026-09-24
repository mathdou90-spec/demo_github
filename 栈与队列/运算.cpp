#include <iostream>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin>>s;
    ll sum=0;
    ll cur=0;
    ll prod=1;
    bool inMul=false;
    for(char c:s) {
        if(isdigit(c)) cur=cur*10+(c-'0');
        else {
            if(inMul) prod*=cur;
            else prod=cur;
            if(c=='+') {
                sum+=prod;
                prod=1;
                inMul=false;
            }
            else if(c=='*') inMul=true;
        }
        cur=0;
    }
    if(inMul) prod*=cur;
    else prod=cur;
    sum+=prod;
    cout<<sum<<endl;
    return 0;
}