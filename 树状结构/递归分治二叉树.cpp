#include <iostream>
#include <string>
using namespace std;

string buildPostorder(const string &pre,const string &in) {
    if(pre.empty()) return "";
    char root=pre[0];
    size_t pos=in.find(root);
    string leftin=in.substr(0,pos);
    string rightin=in.substr(pos+1);
    string leftpre=pre.substr(1,pos);
    string rightpre=pre.substr(pos+1);
    return buildPostorder(leftpre,leftin)+buildPostorder(rightpre,rightin)+root;
}

int main() {
    string pre,in;
    while(cin>>pre>>in) {
        cout<<buildPostorder(pre,in)<<endl;
    }
    return 0;
}