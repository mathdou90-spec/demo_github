#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

struct DoubleListNode {
    int val;
    DoubleListNode* next;
    DoubleListNode* last;
    DoubleListNode(int x):val(x),last(nullptr),next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* pre=nullptr;
    ListNode* tmpnext=nullptr;
    while(head) {
        tmpnext=head->next;
        head->next=pre;
        pre=head;
        head=tmpnext;
    }
    return pre;
}

DoubleListNode* reverseDoubleList(DoubleListNode* head) {
    DoubleListNode* pre=nullptr;
    DoubleListNode* tmpnext=nullptr;
    while(head) {
        tmpnext=head->next;
        head->last=pre;
        head->next=pre;
        pre=head;
        head=tmpnext;
    }
    return pre;
}
//归并排序链表
ListNode* mergeTwoList(ListNode* head1,ListNode* head2) {
    if(head1==nullptr||head2==nullptr) {
        return head1==nullptr?head2:head1;
    }
    ListNode* head=head1->val<=head2->val?head1:head2;
    ListNode* cur1=head->next;
    ListNode* cur2=head==head1?head2:head1;
    ListNode* pre=head;
    while(head1&&head2) {
        if(cur1->val<=cur2->val) {
            pre->next=cur1;
            cur1=cur1->next;
        }
        else {
            pre->next=cur2;
            cur2=cur2->next;
        }
        pre=pre->next;
    }
    pre->next=cur1!=nullptr?cur1:cur2;
    return head;
} 

ListNode* addTowNumber(ListNode* head1,ListNode* head2) {
    ListNode dummy(0);
    ListNode* cur=&dummy;
    int carry=0;
    while(head1!=nullptr||head2!=nullptr) {
        int x=(head1!=nullptr)?head1->val:0;
        int y=(head2!=nullptr)?head2->val:0;
        int sum=x+y+carry;
        carry=sum/10;
        cur->next=new ListNode(sum%10);
        cur=cur->next;
        if(head1!=nullptr) head1=head1->next;
        if(head2!=nullptr) head2=head2->next;
        }
        if(carry>0) {
            cur->next=new ListNode(carry);
        }
        return dummy.next;
}

ListNode* partition(ListNode* head,int x) {
    ListNode* leftHead=nullptr;
    ListNode* leftTail=nullptr;
    ListNode* rightHead=nullptr;
    ListNode* rightTail=nullptr;
    ListNode* next=nullptr;
    while(head!=nullptr) {
        next=head->next;
        head->next=nullptr;
        if(head->val<x) {
            if(leftHead==nullptr) leftHead=head;
            else leftTail->next=head;
        }
        else {
            if(rightHead==nullptr) rightHead=head;
            else rightTail->next=head;
        }
        head=next;
    }
    if(leftHead==nullptr) return rightHead;
    leftTail->next=rightHead;
    return leftHead;
}