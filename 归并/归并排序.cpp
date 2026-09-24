#include <iostream>
using namespace std;
int help[10000];
int arr[10000];

void meragsort1(int l,int r) {
    if(l==r) return;
    int m=l+(r-l)/2;
    meragsort1(l,m);
    meragsort1(m+1,r);
    merag(l,m,r);
}

void meragsort2(int l,int r) {
    for(int l,m,r,step=1;step<n;step<<=1) {
        l=0;
        while(l<n) {
            m+1=l+step-1;
            if(m+1>=n) break;
            r=min(l+(step<<1)-1,n-1);
            merag(l,m,r);
            l=r+1;
        }
    }
}

void merag(int l,int m,int r) {
    int i=l;
    int a=l;
    int b=m+1;
    while(a<=m&&b<=r) {
        help[i++]=arr[a]<=arr[b]?arr[a++]:arr[b++];    //x++先返回x,再加1
    }
    while(a<=m) {
        help[i++]=arr[a++];
    }
    while(b<=r) {
        help[i++]=arr[b++];
    }
    for(i=l;i<=r;i++) {
        arr[i]=help[i];
    }
}