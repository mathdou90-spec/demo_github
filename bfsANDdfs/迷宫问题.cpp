#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x,y;
};

const int N=5;
vector<vector<int>> maze(N,vector<int>(N));
vector<vector<Point>> prev1(N,vector<Point>(N,{-1,-1}));
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void bfs() {
    queue<Point> q;
    q.push({0,0});
    maze[0][0]=1;
    while(!q.empty()) {
        Point p=q.front();
        q.pop();
        if(p.x==N-1 && p.y==N-1) return;
        for(int i=0;i<4;i++) {
            int nx=p.x+dx[i],ny=p.y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<N && maze[nx][ny]==0) {
                maze[nx][ny]=maze[p.x][p.y]+1;
                prev1[nx][ny]=p;
                q.push({nx,ny});
            }
        }
    }
}

int main() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>maze[i][j];
        }
    }
    bfs();
    vector<Point> path;
    Point p={N-1,N-1};
    while(p.x!=-1 && p.y!=-1) {
        path.push_back(p);
        p=prev1[p.x][p.y];
    }
    reverse(path.begin(),path.end());
    for(auto p:path) {
        cout<<"("<<p.x<<","<<p.y<<")"<<endl;
    }
    return 0;
}