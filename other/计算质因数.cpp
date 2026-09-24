#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> factors;
int gcd(int a,int b) {
    if(b==0) return a;
    return gcd(b,a%b);
}
int main() {
    int M;
    cin>>M;
    ll tmp=M;
    for(int i=2;i*i<=tmp;i++) {
        if(tmp%i==0) {
            factors.push_back(i);
            while(tmp%i==0) tmp/=i;
        }
    }
    if(tmp>1) factors.push_back(tmp);
    return 0;
}