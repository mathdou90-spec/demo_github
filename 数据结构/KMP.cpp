#include <iostream>
#include <vector>
#include <string>
using namespace std;

void get_next(const string &s,vector<int> &next) {
    int i=1,j=0;
    next[0]=-1;
    next[1]=0;
    while(i<s.size()) {
        if(j==0||s[i]==s[j]) {
            i++;
            j++;
            next[i]=j;
        } else {
            j=next[j];
        }
    }
}

int Index_KMP(const string &s,const string &p,vector<int> &next ) {
    int i=0,j=0;
    while(i<p.size()&&j<s.size()) {
        if(j==0||p[i]==s[j]) {
            i++;
            j++;
        } else {
            j=next[j];
        }
    }
    if(i==p.size()) {
        return i-j;
    }
    return -1;
}