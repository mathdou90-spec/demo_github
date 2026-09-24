#include <iostream>
using namespace std;

void decimalToBinaryRecursive(int n) {
    if (n > 1) {
        decimalToBinaryRecursive(n / 2);
    }
    cout << n % 2;
}

int main() {
    int decimal;
    cout << "请输入一个十进制数: ";
    cin >> decimal;
    
    cout << "二进制表示: ";
    if (decimal == 0) {
        cout << "0";
    } else {
        decimalToBinaryRecursive(decimal);
    }
    cout << endl;
    
    return 0;
}