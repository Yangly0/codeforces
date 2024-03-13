#include <bits/stdc++.h>
using namespace std;

/*
## 题目

https://codeforces.com/problemset/problem/45/I

输入 n(1≤n≤100) 和长为 n 的数组 a(-100≤a[i]≤100)。
你需要从 a 中选择若干个数（至少一个），最大化所选数字的乘积。
输出你选的数字。如果答案不唯一，输出任意一个。

## 样例

输入
5
1 2 -3 3 3
输出 3 1 2 3

输入
13
100 100 100 100 100 100 100 100 100 100 100 100 100
输出 100 100 100 100 100 100 100 100 100 100 100 100 100

输入
4
-2 -2 -2 -2
输出 -2 -2 -2 -2

## 难度

1400

## 题解

把所有非零数相乘，如果结果是负数（有奇数个负数），就去掉一个绝对值最小的负数（最大的负数）。

corner case：
1. 如果 n=1，直接输出 a[0]。
2. 如果全为 0，或者一个负数和 n-1 个 0，输出 0。

*/

void solve() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int neg = 0, zoro = 0, mxI = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            ++neg;
            if (mxI < 0 || a[i] > a[mxI]) {
                mxI = i;
            }
        } else if (a[i] == 0) {
            ++zoro;
        }
    }

    if (n == 1) {
        cout << a[0];
        return;
    }

    if (zoro == n || (neg == 1 && zoro == n - 1)) {
        cout << 0;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] != 0 && (neg % 2 == 0 || i != mxI)) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

int main(int args, char *argv[]) {
#if 1
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