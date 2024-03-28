/*
## 题目

https://codeforces.com/problemset/problem/1702/E

输入 T(≤1e4) 表示 T 组数据。所有数据的 n 之和 ≤2e5。
每组数据输入 n(2≤n≤2e5) 表示 n 块骨牌，每块骨牌上写有两个数。
然后输入 n 行，每行 2 个数，表示骨牌上的数字，范围 [1,n]。

你需要把这 n 块骨牌分成两组，使得每组内都不含重复数字。
能否做到？输出 YES 或 NO。

例如有 4 块骨牌：(1,4), (1,3), (3,2), (4,2)。
可以分成如下两组：
第一组：(1,4), (3,2)。
第二组：(1,3), (4,2)。

## 样例

输入
6
4
1 2
4 3
2 1
3 4
6
1 2
4 5
1 3
4 6
2 3
5 6
2
1 1
2 2
2
1 2
2 1
8
2 1
1 2
4 3
4 3
5 6
5 7
8 6
7 8
8
1 2
2 1
4 3
5 3
5 4
6 7
8 6
7 8
输出
YES
NO
NO
YES
YES
NO

## 难度

1600

## 思路

错误思路：创建两个哈希表，贪心选择哈希表。

正确思路：
1. n对数字，数字范围[1, n]，则每个数必须恰好出现两次，否则根据鸽巢原理，必然有个集合有重复数字。
2. 把每对数字看成边，我们得到的图一定是由若干个不相交的环组成。如果每个环的长度都是偶数，那么输出 YES，否则输出 NO。
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T, n;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> n;

        vector<vector<int>> g(n);
        int a, b;

        bool ans = true;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            --a;
            --b;
            g[a].emplace_back(b);
            g[b].emplace_back(a);

            if (a == b || g[a].size() > 2 || g[b].size() > 2) {
                ans &= false;
            }
        }

        if (!ans) {
            cout << "NO\n";
            continue;
        }

        // 环长度
        vector<int> used(n + 1, false);
        function<int(int)> dfs = [&](int v) {
            used[v] = true;
            for (auto now : g[v]) {
                if (!used[now]) {
                    return dfs(now) + 1;
                }
            }
            return 1;
        };

        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                if (dfs(i) % 2) {
                    ans &= false;
                    break;
                }
            }
        }

        cout << ((ans) ? "YES" : "NO") << "\n";
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