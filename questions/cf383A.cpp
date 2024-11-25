/*
## 题目

https://codeforces.com/problemset/problem/383/A

输入 n(1≤n≤2e5) 和长为 n 的数组 a，只包含 0 和 1。

你按照某种顺序，标记这 n 个数字。
当你标记一个数字 a[i] 时，统计 a[i] 左边所有没有被标记的 1 的个数，和右边所有没有被标记的 0 的个数，加入答案。

输出答案的最小值。

## 样例

输入
4
0 0 1 0
输出 1
解释 按照下标 2,3,1,0 的顺序标记这 4 个数。

输入
5
1 0 1 0 1
输出 3

## 难度

1600

## 思路

把 0 视作左箭头 ←，把 1 视作右箭头 →。
考虑两个箭头标记的先后顺序：
1. 两个箭头背靠背：先标记谁都不影响答案。
2. 两个箭头面对面：先标记谁都会把答案加一。
3. 两个箭头都朝右：先标记左边的，这样不影响答案。
4. 两个箭头都朝左：先标记右边的，这样不影响答案。

对于朝右的箭头，我们从左往右标记。
对于朝左的箭头，我们从右往左标记。

在这种操作顺序下，只有面对面的箭头会对答案有贡献。
所以只需要统计有多少对箭头是面对面的。

*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a;
    cin >> n;

    long long ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a > 0) {
            ++cnt;
        } else {
            ans += cnt;
        }
    }
    cout << ans << endl;
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