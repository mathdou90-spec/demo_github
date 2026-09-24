#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct student{
    int score[5];
    string name;
    double endscore;
     void calculatesocre(const int credit[5]){
        double total=0.0;
        int totalcredit=0;
        for(int i=0;i<5;i++) {
            totalcredit+=credit[i];
            total+=score[i]*credit[i];
        }
        endscore=total/totalcredit;
     }
};
bool comparebyscore(const student &a,const student &b) {
            return a.endscore>b.endscore;
        }
int main() {
    int credit[5];
    int total=0;
    for(int i=0;i<5;i++) {
        cin>>credit[i];
    }
    int n;
    cin>>n;
    struct student students[n];
    for(int j=0;j<n;j++) {
        cin>>students[j].name;
        for(int k=0;k<5;k++) {
            cin>>students[j].score[k];
        }
        students[j].calculatesocre(credit);
    }
    sort(students,students+n,comparebyscore);
    cout<<fixed<<setprecision(2);
    for(int i=0;i<n;i++) {
        cout<<students[i].name<<" "<<students[i].endscore<<endl;
    }
    return 0;
}