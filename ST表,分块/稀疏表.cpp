#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> heigth(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> heigth[i];
    }
    // 2的多少次幂不超过N
    int Log = log2(N) + 1;
    vector<vector<int>> max_st(N + 1, vector<int>(Log));
    vector<vector<int>> min_st(N + 1, vector<int>(Log));
    // 长度为1时,初始最值
    for (int i = 1; i <= N; i++)
    {
        max_st[i][0] = min_st[i][0] = heigth[i];
    }
    // 稀疏表按列输入
    for (int j = 1; (1 << j) <= N; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= N; i++)
        {
            max_st[i][j] = max(max_st[i][j - 1], max_st[i + (1 << (j - 1))][j - 1]);
            min_st[i][j] = min(min_st[i][j - 1], min_st[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (Q--)
    {
        int A, B;
        cin >> A >> B;
        int k = log2(B - A + 1);
        int max_val= max(max_st[A][k], max_st[B - (1 << k) + 1][k]);
        int min_val= min(min_st[A][k], min_st[B - (1 << k) + 1][k]);
        cout<<max_val-min_val<<"\n";
    }
}