#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int used[100],len[100],sum,n,Min;
inline int find(int pos,int rest,int trest) {  //rest剩余需要拼凑长度,trest剩余总长度
    int i;
    if(trest==Min) return 1;
    for(i=pos;i<=n;i++) {
        if(!used[i]&&len[i]<=rest) {
            used[i]=1;
            if(len[i]==rest) {
                if(find(1,Min,trest-len[i])) return 1;
            }
            else if(find(i+1,rest-len[i],trest-len[i])) return 1;
            used[i]=0;
            if(rest==Min) return 0;
            while(len[i+1]==len[i]) i++;
        }
    }
    return 0;
}
bool cmp(int a,int b) {return a>b;}
int main() {
    int i;
    while(cin>>n && n) {
        Min=0;
        sum=0;
        for(i=1;i<=n;i++) {
            cin>>len[i];
            sum+=len[i];
        }
        memset(used,0,sizeof(used));
        sort(len+1,len+n+1,cmp);
        Min=len[1];
        while(sum%Min!=0&&Min<sum) Min++;
        while(find(1,Min,sum)==0) {
            Min++;
            while(sum%Min!=0&&Min<sum) Min++;
        }
        cout<<Min<<endl;
    }
    return 0;
}