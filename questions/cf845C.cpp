/*
## 题目

https://codeforces.com/problemset/problem/845/C

输入 n(1≤n≤2e5) 和 n 个闭区间，每个闭区间 [L,R] 都满足 0≤L<R≤1e9。
能否将这 n 个闭区间分成两组，每组内的区间交集为空？允许一组是空的。
输出 YES 或 NO。

## 样例

输入
3
1 2
2 3
4 5
输出 YES

输入
4
1 2
2 3
2 3
1 2
输出 NO

## 难度

1500


## 思路

贪心：
1. 定义两个变量 end1 和 end2 分别表示两个集合的最大右端点，初始值为 -1。
2. 把区间按照左端点从小到大排序。
3. 遍历区间，如果区间左端点比 end1 和 end2
都大，那么放在哪个集合都是可以的（因为后面遍历的区间左端点只会更大）。如果只比一个大就放入对应集合。否则输出NO。 如果遍历中没有输出 NO 就输出 YES。
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    int end1 = -1, end2 = -1;

    for (auto x : arr) {
        if (end1 <= end2) {
            if (end1 < x.first) {
                end1 = x.second;
            } else {
                cout << "NO" << endl;
                return;
            }
        } else {
            if (end2 < x.first) {
                end2 = x.second;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
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