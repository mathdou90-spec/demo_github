#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class quickSort {
    private:
    vector<int> arr;
    int partion(int l,int r) {
        int randomIdx=l+rand()%(r-l+1);
        swap(arr[randomIdx],arr[r]);
        int i=l-1;
        int value=arr[l];
        for(int j=l;j<r;j++) {
            if(arr[j]<value) {
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[r]);
        return i+1;
    }
    public:
    quickSort(const vector<int>& arr,int l,int h) {
        if(l<h) {
            int p=partion(l,h);
            quickSort(arr,l,p-1);
            quickSort(arr,p+1,h);
        }
    }
};