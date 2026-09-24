#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 3000000;
long long phi[MAXN + 1];      // 改用 long long 存储前缀和
bool isComp[MAXN + 1];
vector<int> primes;

void compute_phi() {
    phi[1] = 1;
    for (int i = 2; i <= MAXN; ++i) {
        if (!isComp[i]) {
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for (int p : primes) {
            long long nxt = 1LL * i * p;
            if (nxt > MAXN) break;
            isComp[nxt] = true;
            if (i % p == 0) {
                phi[nxt] = phi[i] * p;
                break;
            } else {
                phi[nxt] = phi[i] * (p - 1);
            }
        }
    }
    // 计算前缀和，复用 phi 数组
    for (int i = 2; i <= MAXN; ++i) {
        phi[i] += phi[i - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    compute_phi();
    int a, b;
    while (cin >> a >> b) {
        cout << phi[b] - phi[a - 1] << '\n';   // 用 '\n' 而不是 endl，避免刷新缓冲区
    }
    return 0;
}