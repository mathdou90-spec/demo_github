#include <iostream>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin>>s;
    s=s+'+';
    stack<ll> st;
    ll cur=0;
    for(char c:s) {
        if(isdigit(c)) {
            cur=cur*10+(c-'0');
        }
        else {
            st.push(cur);
            cur=0;
            if(c=='+') {
                while(st.size()>1) {
                    ll a=st.top(); st.pop();
                    ll b=st.top(); st.pop();
                    st.push(a+b);
                }
            }
            else if(c=='*') {
                while(st.size()>1) {
                    ll a=st.top(); st.pop();
                    ll b=st.top(); st.pop();
                    st.push(a*b);
                }
            }
        }
    }
    cout<<st.top()<<endl;
    return 0;
}