/*
## 题目

https://codeforces.com/problemset/problem/520/B

输入两个不同的整数 n m，范围都在 [1,1e4]。

每次操作，可以 n*=2，或者 n-=1。
至少操作多少次可以得到 m？

如果还可以加一呢？
https://codeforces.com/problemset/problem/710/E

## 样例

输入 4 6
输出 2

输入 10 1
输出 9

## 难度

1400

## 思路

https://codeforces.com/contest/520/submission/204549550

如果 n > m，就只能不断 -1 了，所以直接输出 n-m。

如果 n < m，可以用 BFS（稍微限制一下数字的上界，比如不能超过 10m）。

下面说一个 O(log) 的做法。

由于 *2 不稳定（不知道什么时机 *2 最好），逆向思维，改成从 m 出发，通过 /2 和 +1 变成 n。

能不能执行连续两次 +1，再 /2 呢？

这不如先 /2 再 +1，只需要两次操作
所以只要 m 是偶数就 /2，奇数才 +1。直到 m <= n 退出循环，因为必须都 +1。这样可以做到 O(log) 的时间复杂度。

O(1) 做法见右侧链接。

*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, ans;
    cin >> n >> m;

    ans = 0;
    while (m > n) {
        if (m % 2 == 0) {
            m /= 2;
        } else {
            m++;
        }
        ans++;
    }
    cout << ans + n - m << endl;
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