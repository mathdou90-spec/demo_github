#include <iostream>
#include <vector>
using namespace std;

struct Point{
    double x1,y1,x2,y2;
};

bool sameLine(Point &p1,Point &p2) {
    if(p1.x1-p1.x2==0 || p2.x1-p2.x2==0) {
        if(p1.x1-p1.x2==0 && p2.x1-p2.x2==0) return true;
        else return false;
    }
    if((p1.x1==p1.x2&&p1.y1==p1.y2)||(p2.x1==p2.x2&&p2.y1==p2.y2)) return false;
    if((p1.x1-p1.x2)*(p2.y1-p2.y2)==(p2.x1-p2.x2)*(p1.y1-p1.y2)) return true;
    else return false;
}

int main() {
    int T;
    cin>>T;
    while (T--) {
        int n;
        cin>>n;
        Point p[n];
        for(int i=0;i<n;i++) {
            cin>>p[i].x1>>p[i].y1>>p[i].x2>>p[i].y2;
        }
        bool can=true;
        for(int i=1;i<n;i++) {
            if(!sameLine(p[i-1],p[i])) {
                can=sameLine(p[i-1],p[i]);
                break;
            }
        }
        if(can) cout<<"Yes!"<<endl;
        else cout<<"No!"<<endl;
    }
}