#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void selectionSort(vector<int> &arr) {
    int n=arr.size();
    for(int i=0;i<n-1;i++) {
        int minIndex=i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[minIndex]) minIndex=j;
        }
        if(minIndex!=i) swap(arr[i],arr[minIndex]);
    }
}

void bubbleSort(vector<int> &arr) {
    int n=arr.size();
    for(int i=0;i<n-1;i++) {
        bool swapped=false;
        for(int j=0;j<n-1-i;j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
}

void insertionSort(vector<int> &arr) {
    int n=arr.size();
    for(int i=1;i<n;i++) {
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
} 

vector<int> randomArray(int size,int maxval) {
    vector<int> arr(size);
    for(int i=0;i<size;i++) {
        arr[i]=rand()%(maxval+1);
        //rand()用于返回一个介于0到32767及以上的随机整数
    }
    return arr;
}

vector<int> copyArray(vector<int> &arr) {
    int n=arr.size();
    vector<int> ans(n);
    for(int i=0;i<n;i++) {
        ans[i]=arr[i];
    }
    return ans;
}

bool sameArray(vector<int> &arr1,vector<int> &arr2) {
    int n1=arr1.size();
    int n2=arr2.size();
    if(n1!=n2) return false;
    for(int i=0;i<n1;i++) {
        if(arr1[i]!=arr2[i]) return false;
    }
    return true;
}

int main() {
    int size,maxval,testTime;
    cout<<"请输入数组最大长度,上限值与测试次数:"<<endl;
    cin>>size>>maxval>>testTime;
    cout<<"测试开始."<<endl;
    for(int i=0;i<testTime;i++) {
        int the_size=rand()%(size+1);
        vector<int> arr=randomArray(the_size,maxval);
        vector<int> arr1=copyArray(arr);
        vector<int> arr2=copyArray(arr);
        vector<int> arr3=copyArray(arr);
        selectionSort(arr1);
        bubbleSort(arr2);
        insertionSort(arr3);
        if(!sameArray(arr1,arr2)||!sameArray(arr1,arr3)) {
            cout<<"出错了!"<<endl;
        }
    }
    cout<<"测试结束."<<endl;
    return 0;
}