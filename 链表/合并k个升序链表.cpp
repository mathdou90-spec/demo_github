#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}    //空链表初始化
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
//自定义比较器,true表示优先级小,因此a>b表示a的优先级小于b,即a排在b后面
    struct Compare {
            bool operator()(ListNode* a,ListNode* b) {
                return a->val>b->val;
            }
        };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //优先队列第一个为元素类型,第二个为底层容器类型,如果不写默认vector<...>，第三个为比较器类型
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        for(ListNode* head: lists) {
            if(head) pq.push(head);
        }
        //创建一个虚拟头结点，方便返回结果
        ListNode dummy(0);
        ListNode* tail=&dummy;
        while(!pq.empty()) {
            ListNode* cur=pq.top();
            pq.pop();
            //通过尾指针移动并链接
            tail->next=cur;
            tail=cur;
            if(cur->next) {
                pq.push(cur->next);
            }
        }
        //虚拟头结点的next指针指向合并后的链表头结点
        return dummy.next;
    }
};