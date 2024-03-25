/*
## 题目

https://codeforces.com/problemset/problem/1443/B

输入 T(≤1e5) 表示 T 组数据。所有数据的字符串长度之和 ≤1e5。
每组数据输入 a(1≤a≤1000) b(1≤b≤1000) 和长度不超过 1e5 的 01 字符串。

你可以花费 a，把一段连续的 1 变成 0。
也可以花费 b，把一个 0 变成 1。
上述两种操作可以执行任意次。

输出把所有 1 都变成 0 的最小花费。

## 样例

输入
2
1 1
01000010
5 1
01101110
输出
2
6

## 难度

1300

## 思路


*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T, a, b;
    string str;
    cin >> T;
    while (T-- > 0) {
        cin >> a >> b;
        cin >> str;
    }
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