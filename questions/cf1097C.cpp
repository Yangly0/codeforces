/*
## 题目

https://codeforces.com/problemset/problem/1097/C

输入 n(1≤n≤1e5) 和 n 个括号字符串，字符串长度之和 ≤5e5。
你需要从中选出 2m 个括号，两两一对，拼接成 m 个合法括号字符串。
输出 m 的最大值。

## 样例

输入
7
)())
)
((
((
(
)
)
输出 2
解释 (( + )()) 和 ( + )

输入
4
(
((
(((
(())
输出 0

输入
2
(())
()
输出 1

## 难度

1400

## 思路

处理括号字符串 s 的通用方法：
遍历 s，用一个变量 cnt 记录 s 前缀的左括号的个数减去右括号的个数。
如果 s 是合法括号字符串，那么在遍历的过程中 cnt >= 0，且遍历结束后 cnt = 0。

把拼接的字符串分别记作 S 和 T，即 S+T 是合法括号字符串。
设 S 的 cnt 值为 cntS，要求遍历过程中的 cntS 的最小值 >= 0。
设 T 的 cnt 值为 cntT，要求遍历过程中的 cntT 的最小值等于遍历结束后的 cntT。
如果 S+T 是合法括号字符串，那么 cntS + cntT = 0。

用数组/哈希表维护 cnt 的出现次数。
设 mn 为 cnt 的最小值。如果 mn = 0 或者 mn = cnt，先看 -cnt 是否有，如果有，就找到了一对，答案加一，同时把 -cnt 的出现次数减一；如果没有，就把 cnt
的出现次数加一。

*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    unordered_map<char, int> mp = {{'(', 1}, {')', -1}};
    unordered_map<int, int> seen;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        int cnt = 0, mn = 0;
        for (auto ch : s) {
            cnt += mp[ch];
            mn = min(mn, cnt);
        }

        if (mn == 0 || mn == cnt) {
            if (seen[-cnt] > 0) {
                seen[-cnt]--;
                ans++;
            } else {
                seen[cnt]++;
            }
        }
    }
    cout << ans << endl;
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