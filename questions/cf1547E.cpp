/*
## 题目

https://codeforces.com/problemset/problem/1547/E

输入 T(≤1e4) 表示 T 组数据。所有数据的 n 之和 ≤3e5。
每组数据输入 n k (1≤k≤n≤3e5)，长为 k 的数组 a(1≤a[i]≤n)，长为 k 的数组 t(1≤t[i]≤1e9)。

数轴上有 k 个正在制冷的空调，第 i 个空调的位置是 a[i]，温度为 t[i]。
位置 j 的温度会受到空调 i 的影响，离空调越远，温度越高，具体温度为 t[i] + |a[i] - j|。
如果位置 j 被多个空调影响，取温度最小值。

输出 1~n 每个位置的温度。

## 样例

输入
5

6 2
2 5
14 16

10 1
7
30

5 5
3 1 4 2 5
3 1 4 2 5

7 1
1
1000000000

6 3
6 1 3
5 5 5
输出
15 14 15 16 16 17
36 35 34 33 32 31 30 31 32 33
1 2 3 4 5
1000000000 1000000001 1000000002 1000000003 1000000004 1000000005 1000000006
5 6 5 6 6 5

## 难度

1500

## 思路

设 f[i] 是位置 i 的温度。如果 i 位置有空调，那么初始化 f[i] 为对应温度，否则 f[i]=inf。
考虑 i 左侧空调的影响。
如果我们知道了 f[i-1] 的温度，那么 f[i] 的温度就是 min(f[i], f[i-1]+1)。
这可以从左到右递推算出。
对于 i 右侧空调也一样，有 f[i] = min(f[i],f[i+1]+1)，从右到左递推算出。
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T, n, k, t;
    cin >> T;

    while (T--) {
        cin >> n >> k;

        vector<int> a(k, -1);
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
        }

        vector<int> f(n, INT_MAX - 1);
        for (int i = 0; i < k; ++i) {
            cin >> t;
            f[a[i] - 1] = t;
        }

        for (int i = n - 2; i >= 0; --i) {
            f[i] = min(f[i], f[i + 1] + 1);
        }

        int mn = INT_MAX - 1;
        for (int i = 0; i < n; ++i) {
            mn = min(f[i], mn + 1);
            cout << mn << " ";
        }
        cout << endl;
    }
}

int main(int args, char *argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

#if 0
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}