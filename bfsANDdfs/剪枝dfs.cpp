#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int sticks[25];
bool used[25];
int N, target;

bool dfs(int edge, int curLen, int start) {
    if (edge == 4) return true;        // 四条边都拼好了
    if (curLen == target)              // 当前边拼好，拼下一条边
        return dfs(edge + 1, 0, 0);

    for (int i = start; i < N; ++i) {
        if (used[i]) continue;
        if (curLen + sticks[i] > target) continue;

        used[i] = true;
        if (dfs(edge, curLen + sticks[i], i + 1))
            return true;
        used[i] = false;

        // 剪枝1：空桶放第一根就失败，后面无解
        if (curLen == 0) return false;

        // 剪枝2：恰好拼满当前边，却失败，后面无解
        if (curLen + sticks[i] == target) return false;

        // 剪枝3：跳过相同长度的木棒
        while (i + 1 < N && sticks[i + 1] == sticks[i])
            i++;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            cin >> sticks[i];
            sum += sticks[i];
        }
        target = sum / 4;
        if (sum % 4 != 0 || *max_element(sticks, sticks + N) > target) {
            cout << "no" << endl;
            continue;
        }
        sort(sticks, sticks + N, greater<int>()); // 大到小排序
        memset(used, 0, sizeof(used));
        if (dfs(0, 0, 0))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}