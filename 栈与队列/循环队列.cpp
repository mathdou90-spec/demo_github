#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class CricularQueue {
private:
    T* arr;
    int capacity;
    int front;
    int rear;
public:
    explicit CricularQueue(int cap):capacity(cap+1),front(0),rear(0) {
        if(cap<=0) throw invalid_argument("Capacity must be positive");
        arr=new T[capacity];
    }
    ~CricularQueue() {
        delete[] arr;
    }
    CricularQueue(const CricularQueue&)=delete;
    CricularQueue& operator=(const CricularQueue&)=delete;

    bool isEmpty() const {
        return front==rear;
    }
    bool isFull() const {
        return (rear+1)%capacity=front;
    }
    void enqueue(const T& value) {
        if(isFull()) {
            throw overflow_error("Queue is full");
        }
        arr[rear]=value;
        rear=(rear+1)%capacity;
    }
    void dequeue() {
        if(isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        front=(front+1)%capacity;
    }
    int size() const {
        return (rear-front+capacity)%capacity;
    }
};

class MyCricularDeque {
    private:
    vector<int> deque;
    int l,r;
    int size,limit;

    public:
    MyCricularDeque(int k) {
        deque.resize(k);
        l=r=size=0;
        limit=k;
    }

    bool insertFront(int val) {
        if(isFull()) return false;
        if(isEmpty()) {
            l=r=0;
            deque[0]=val;
        }
        else {
            l=(l==0)?(limit-1):(l-1);
            deque[l]=val;
        }
        size++;
        return true;
    }

    bool insertLast(int val) {
        if(isFull()) return false;
        if(isEmpty()) {
            l=r=0;
            deque[0]=val;
        }
        else {
            r=(r==limit-1)?0:r+1;
            deque[r]=val;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if(isEmpty()) return false;
        if(size==1) {
            l=r=0;
        }
        else {
            l=(l==limit-1)?0:(l+1);
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if(isEmpty()) return false;
        if(size==1) {
            l=r=0;
        }
        else {
            r=(r==0)?(limit-1):(r-1);
        }
        size--;
        return true;
    }

    bool isFull() {
        return size==limit;
    }

    bool isEmpty() {
        return size==0;
    }
};