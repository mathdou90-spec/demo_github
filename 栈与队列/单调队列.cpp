#include <iostream>
#include <vector>
#include <deque>
using namespace std;

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::deque<int> dq;  // 存放下标
    std::vector<int> res;
    
    for (int i = 0; i < nums.size(); ++i) {
        // 移除队尾比当前元素小的（保证队列单调递减）
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        
        // 移除滑出窗口的队首元素
        if (dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // 当窗口形成时记录最大值
        if (i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }
    
    return res;
}

vector<int> minSlidingWindow(vector<int> &nums,int k) {
    deque<int> idx;
    vector<int> res;
    for(int i=0;i<nums.size();i++) {
        while(!idx.empty()&&nums[idx.back()]>=nums[i]) {
            idx.pop_back();
        }
        idx.push_back(i);
        if(idx.front()<=i-k) {
            idx.pop_front();
        }
        if(i>=k-1) {
            res.push_back(nums[idx.front()]);
        }
    }
    return res;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    vector<int> max_ans=maxSlidingWindow(nums,k);
    vector<int> min_ans=minSlidingWindow(nums,k);
    for(int i=0;i<min_ans.size();i++) {
        cout<<min_ans[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<max_ans.size();i++) {
        cout<<max_ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}