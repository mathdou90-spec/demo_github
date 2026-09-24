#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct CompareByVal {
        bool operator()(const ListNode* a,const ListNode* b) const {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        priority_queue<ListNode*,vector<ListNode*>,CompareByVal> pq;
        for(int i=0;i<n;i++) {
            if(lists[i]!=nullptr) pq.push(lists[i]);
        }
        if(pq.empty()) return nullptr;
        ListNode* head=pq.top();pq.pop();
        ListNode* pre=head;
        if(pre->next!=nullptr) {
            pq.push(pre->next);
        }
        while(!pq.empty()) {
            ListNode* cur=pq.top();pq.pop();
            pre->next=cur;
            pre=cur;
            if(cur->next!=nullptr) {
                pq.push(cur->next);

            }
        }
        return head;
    }
};