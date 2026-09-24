#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> fbnc(100);
int main() {
    int N;
    cin>>N;
    fbnc[0]=fbnc[1]="1";
    for(int i=2;i<N;i++) {
    	string a=fbnc[i-1];
    	string b=fbnc[i-2];
    	int carry=0;
    	string c="";
    	for(int j=a.size()-1,k=b.size()-1;j>=0||k>=0;j--,k--) {
    		int x=(j>=0?a[j]-'0':0)+(k>=0?b[k]-'0':0)+carry;
    		c+=x%10+'0';
    		carry=x/10;
		}
		if(carry) c+=carry+'0';
		reverse(c.begin(),c.end());
		fbnc[i]=c;
	}
    cout<<fbnc[N-1];
}