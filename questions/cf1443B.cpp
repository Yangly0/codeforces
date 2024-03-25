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

贪心。
如果没有第二种操作，那么答案就是 a * 连续 1 的段数。
第二种操作可以把两段连续 1 之间的 0 变成 1，这样两段 1 就合并成一段 1，可以减少一个 a 的花费。
如果两段连续 1 之间的 0 的个数 * b < a，那么把 0 变成 1 是更优的，否则不变更优。
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

        int cnt = 0;
        for (char ch : str) {
            if (ch == '1') {
                ++cnt;
            }
        }

        if (cnt == 0) {
            cout << 0 << endl;
            continue;
        }

        int ans = a;
        for (int i = 0, n = str.size(); i < n;) {
            int st = i;
            char v = str[st];

            for (; i < n && str[i] == v; i++) {
            }
            if (v == '0' && st > 0 && i < n) {
                ans += min(b * (i - st), a);
            }
        }
        cout << ans << endl;
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