/*
## 题目

https://codeforces.com/problemset/problem/1187/E

输入 n(2≤n≤2e5) 表示一棵有 n 个节点的无向无根树，然后输入这棵树的 n-1 条边（节点编号从 1 开始）。

一开始，所有节点都是白色的。
第一回合，你可以随便选一个节点，并把它涂成黑色，得到 n 分。
在接下来的 n-1 个回合中，每回合，选择一个与黑色节点相邻的白色节点。设该白色节点所在的白色连通块的大小为 k，你会先得到 k 分，然后把该白色节点涂成黑色。

输出最大得分和。

## 样例

输入
9
1 2
2 3
2 5
2 6
1 4
4 9
9 7
9 8
输出 36

输入
5
1 2
1 3
2 4
2 5
输出 14

## 难度

2100

## 思路

换根 DP。

先通过一次 DFS 求出以 1 为根的得分，以及每棵子树的大小 size[i]。
然后换根，从根 v 换到根 w 时，得分减少了 size[w]，增加了 n-size[w]。后者是因为除去子树 w 的其余节点成为了一棵新的子树，其大小为 n-size[w]。

*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n;

    vector<vector<int>> grid(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        grid[a].emplace_back(b);
        grid[b].emplace_back(a);
    }

    vector<long long> size(n + 1, 0);
    function<long long(int, int)> dfs = [&](int x, int fa) {
        size[x] = 1;

        long long sum = 0;
        for (auto y : grid[x]) {
            if (y != fa) {
                sum += dfs(y, x);
                size[x] += size[y];
            }
        }
        return sum + size[x];
    };

    long long ans = 0;
    function<void(int, int, long long)> reroot = [&](int x, int fa, long long res) {
        ans = max(ans, res);
        for (auto y : grid[x]) {
            if (y != fa) {
                reroot(y, x, res + n - size[y] * 2);
            }
        }
    };

    reroot(1, 0, dfs(1, 0));

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