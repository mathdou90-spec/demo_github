#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int dx[8]={-1,1,0,0,-1,-1,1,1};
const int dy[8]={0,0,-1,1,-1,1,-1,1};

int main() {
    int N,M;
    cin>>N>>M;
    vector<string> field(N);
    for(int i=0;i<N;i++) {
        cin>>field[i];
    }

    vector<vector<bool>> visited(N,vector<bool>(M,false));

    int ans=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(field[i][j]=='W'&&!visited[i][j]) {
                ans++;
                //BFS
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j]=true;
                while (!q.empty()) {
                    auto [x,y]=q.front();
                    q.pop();
                    for(int k=0;k<8;k++) {
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(nx>=0&&ny>=0&&nx<N&&ny<M) {
                            if(field[nx][ny]=='W'&&!visited[nx][ny]) {
                                visited[nx][ny]=true;
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}