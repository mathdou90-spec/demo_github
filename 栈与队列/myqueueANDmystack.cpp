#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
    private:
    stack<int> in;
    stack<int> out;
    void transfer() {
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }
    public:
    void push(int x) {
        in.push(x);
    }
    int pop() {
        transfer();
        int val=out.top();
        out.pop();
        return val;
    }
    int peek() {
        transfer();
        return out.top();
    }
    bool empty() {
        return in.empty()&&out.empty();
    }
};

class MyStack {
    private:
    queue<int> q1,q2;
    public:
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    int pop() {
        int val=q1.front();
        q1.pop();
        return val;
    }
    int top() {
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
};