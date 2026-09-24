#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
    public:
    int Soulation (vector<vector<int>>& line) {
            sort(line.begin(),line.end(),
                [](const vector<int>& a,const vector<int>& b) {
                    return a[0]<b[0];
                }); 
        	priority_queue<int,vector<int>,greater<int>> pq;
        	int ans=0;
        	for(int i=0;i<line.size();i++) {
        		pq.push(line[i][1]);
        		while(!pq.empty()&&pq.top()<=line[i][0]) {
        			pq.pop();
				}
				int temp=pq.size();
				ans=max(ans,temp); 
			}
			return ans;
		} 
};

int main() {
    int n;
    cin>>n;
    vector<vector<int>> line(n,vector<int>(2));
    for(int i=0;i<n;i++) {
        cin>>line[i][0]>>line[i][1];
    }
    Solution s;
    cout<<s.Soulation(line)<<endl;
}