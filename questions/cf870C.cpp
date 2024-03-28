/*
## 题目

https://codeforces.com/problemset/problem/870/C

输入 T(≤1e5) 表示 T 组数据。
每组数据输入 n(1≤n≤1e9)。

把 n 表示成尽量多的合数之和。
例如 12 = 4 + 4 + 4。

输出合数的个数。
如果无法做到，输出 -1。

注：合数为大于 1 的非质数。

## 示例

输入
1
12
输出
3

输入
2
6
8
输出
1
2

输入
3
1
2
3
输出
-1
-1
-1

## 难度

1300

## 思路

由于 4 是最小合数，我们可以分出尽量多的 4。

如果 n=4k，那么答案是 n/4。
如果 n=4k+2，最后余下的 2 可以和 4 组成一个合数 6，所以答案是 n/4。
如果 n=4k+1，最后余下的 1 可以和两个 4 组成一个合数 9，所以答案是 n/4 - 1。
如果 n=4k+3，最后余下的 3 拆分成 2+1，和三个 4 组成合数 6 和合数 9，所以答案是 n/4 - 1。
综上所述，答案为 n/4 - n%2。

特殊情况：如果 n 是 1,2,3,5,7,11，输出 -1。其中 1 和 3 可以整合到上述公式中。


*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        if (n == 1 || n == 3 || n == 2 || n == 5 || n == 7 || n == 11) {
            cout << -1 << endl;
        } else {
            cout << n / 4 - n % 2 << endl;
        }
    }
}

int main(int args, char *argv[]) {
#if 0
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