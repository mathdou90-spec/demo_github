#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

class randomQuickSort{
    private:
    int first,last;
    vector<int> arr;
    void partition(int l,int r,int x) {
        first=l;
        last=r;
        int i=l;
        while(i<=last) {
            if(arr[i]==x) i++;
            else if(arr[i]<x) swap(arr[first++],arr[i++]);
            else swap(arr[i],arr[last--]);
        }
    }
    static mt19937 gen;
    public:
    randomQuickSort(const vector<int>& nums) : arr(nums) {}
    randomQuickSort(const int* nums,int size) : arr(nums,nums+size) {}
    void QuickSort(int l,int r) {
        if(l>=r) return;
        uniform_int_distribution<> dis(l,r);
        int randomIdx=dis(gen);
        int x=arr[randomIdx];
        partition(l,r,x);
        int left=first;
        int right=last;
        QuickSort(l,left-1);
        QuickSort(right+1,r);
    }
};

mt19937 randomQuickSort::gen(random_device{}());