#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<int,int> parent,size;
    int find(int x) {
        if(!parent.count(x)) return x;
        if(parent[x]!=x) {
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x,int y) {  //并查集的合并操作
        int rx=find(x),ry=find(y);
        if(rx==ry) return;
        if(size[rx]<size[ry]) {
            swap(rx,ry);
        }
        parent[ry]=rx;
        size[rx]+=size[ry];
    }
    int longestConsecutive(vector<int>& nums) {
        for(int num:nums) {
            if(parent.count(num)) continue;
            parent[num]=num;
            size[num]=1;
            if(parent.count(num-1)) unite(num,num-1);
            if(parent.count(num+1)) unite(num,num+1);
        }
        int ans=0;
        for(auto& [k,v]:size) {
            ans=max(ans,v);
        }
        return ans;
    }
};