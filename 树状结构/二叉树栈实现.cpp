#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int k): data(k),right(nullptr),left(nullptr) {}
};

void PreOrder (TreeNode* head) {
    if(head==nullptr) return;
    stack<TreeNode*> stk;
    stk.push(head);
    while(!stk.empty()) {
        TreeNode* node=stk.top();
        stk.pop();
        cout<<node->data<<" ";
        if(node->right) stk.push(node->right);
        if(node->left) stk.push(node->left);
    }
    cout<<endl;
}

void inOrder(TreeNode* head) {
    stack<TreeNode*> stk;
    TreeNode *node=head;
    while(node!=nullptr||!stk.empty()) {
        while(curr!=nullptr) {
            stk.push(node);
            node=node->left;
        }
        node=stk.top();
        stk.pop();
        cout<<node->data<<" ";
        node=node->right;
    }
}

void PostOrder(TreeNode* head) {
    if(head==nullptr) return;
    stack<TreeNode*> stk;
    stk.push(head);
    TreeNode* lastPrinted=nullptr;
    while(!stk.empty()) {
        TreeNode* cur=stk.top();
        if(cur->left!=nullptr&&lastPrinted!=cur->left&&lastPrinted!=cur->right) {
            stk.push(cur->left);
        }
        else if(cur->right!=nullptr&&lastPrinted!=cur->right) {
            stk.push(cur->right);
        }
        else {
            cout<<cur->data<<" ";
            lastPrinted=cur;
            stk.pop();
        }
    }
    cout<<endl;
}