#include <iostream>
using namespace std;

// 汉诺塔递归函数
void hanoi(int n, char from, char to, char aux) {
    // 基本情况：只有一个盘子时，直接移动
    if (n == 1) {
        cout << "将盘子 1 从 " << from << " 移动到 " << to << endl;
        return;
    }
    
    // 递归步骤：
    // 1. 将 n-1 个盘子从起始柱移动到辅助柱
    hanoi(n - 1, from, aux, to);
    
    // 2. 将最大的盘子从起始柱移动到目标柱
    cout << "将盘子 " << n << " 从 " << from << " 移动到 " << to << endl;
    
    // 3. 将 n-1 个盘子从辅助柱移动到目标柱
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    
    cout << "请输入汉诺塔的盘子数量：";
    cin >> n;
    
    if (n <= 0) {
        cout << "盘子数量必须大于0！" << endl;
        return 1;
    }
    
    cout << "\n汉诺塔的移动步骤：" << endl;
    hanoi(n, 'A', 'C', 'B');  // A是起始柱，C是目标柱，B是辅助柱
    
    // 计算总步数
    long long totalMoves = (1LL << n) - 1;  // 2^n - 1
    cout << "\n总移动次数: " << totalMoves << endl;
    
    return 0;
}