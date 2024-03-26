/*
## 题目

https://codeforces.com/problemset/problem/166/C

输入 n(1≤n≤500) x(1≤x≤1e5) 和长为 n 的数组 a(1≤a[i]≤1e5)。
向 a 中添加尽量少的数，使得 a 的中位数恰好等于 x。
输出添加的元素个数。

注：如果 n 是偶数，中位数取正中间左边那个。例如 a=[1,3,5,7] 的中位数是 3。

进阶：你能做到（预处理后）对于任意 x，都只用 O(log n) 的时间回答吗？


## 样例

输入
3 10
10 20 30
输出 1
解释：添加 9。

输入
3 4
1 2 3
输出 4
解释：添加 4,5,5,5。

## 难度

1500

## 思路

本题只有一个询问 x，如果改成多个询问（有多个不同的 x），对于每个询问，我们可以做到 O(log n) 的时间回答。

把 a 从小到大排序。
首先，如果 x 不在 a 中，我们得先插入一个 x。
设 i 和 j 分别是最左和最右 x 的下标（下标从 0 开始），这可以二分得到。
设中位数下标 m = (n-1)/2。
如果 i > m，说明 x 太大了，我们可以在 a 末尾添加 2*i-n+1 个数，使得 x 落在下标 m 上。
如果 j < m，说明 x 太小了，同样地，我们可以在 a 开头添加 n-2*j-2 个数，使得 x 落在下标 m 上。
其它情况无需添加。

也可以计算最终的数组长度，减去 n 得到要添加的元素个数，代码见右。
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int i = lower_bound(a.begin(), a.end(), x) - a.begin();
    int j = lower_bound(a.begin(), a.end(), x + 1) - a.begin() - 1;

    int ans = 0;
    if (i == n || a[i] != x) { // 不存在x，插入一个x
        ans = 1;
        j = i;
        ++n;
    }

    int m = (n - 1) / 2;
    if (i > m) {
        ans += i * 2 - n + 1;
    } else if (j < m) {
        ans += n - j * 2 - 2;
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