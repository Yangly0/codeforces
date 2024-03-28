/*
## 题目

https://codeforces.com/problemset/problem/1137/B

输入两个长度均 ≤5e5 的字符串 s 和字符串 t，只包含 '0' 和 '1'。

重排 s 中的字符，使得 s 中有尽量多的子串等于 t。

输出重排后的 s。
如果有多个答案，输出任意一个。

思考题：如果有多个答案，输出其中字典序最小的。@lympanda

## 样例

输入
101101
110
输出
110110

输入
10010110
100011
输出
01100011

输入
10
11100
输出
01

## 难度

1600

## 思路

统计 s 中的 0 和 1 的个数 cnt[0] 和 cnt[1]。

贪心，利用 KMP 去构造答案，因为在子串 t 重叠的时候可以节省尽量多的字符。
把 t 当作模式串，设当前匹配了 j 个，那么只要 cnt[t[j]] > 0，当前这一位就填 t[j]，同时 cnt[t[j]] 减一。
然后 j 加一，如果 j 等于 t 的长度，根据 KMP 匹配的原理，回退到 pi[j-1] 上（见代码）。
如果 cnt[t[j]] = 0，那么后面要填的字母就只有一种了（全 0 或者全 1），直接输出。

代码
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    int cnt[2]{0, 0};
    for (auto ch : s) {
        ++cnt[ch - '0'];
    }

    vector<int> pi(t.size(), 0);
    for (int i = 1, j = 0; i < t.size(); ++i) {
        char v = t[i];
        while (j > 0 && t[j] != v) {
            j = pi[j - 1];
        }
        if (t[j] == v) {
            ++j;
        }
        pi[i] = j;
    }

    string ans{};

    int k = 0;
    while (cnt[t[k] & 1] > 0) {
        ans.push_back(t[k]);
        cnt[t[k] & 1]--;
        k++;
        if (k == t.size()) {
            k = pi[k - 1];
        }
    }
    cout << endl;

    for (int i = 0; i < cnt[0]; ++i) {
        ans.push_back('0' + 0);
    }
    for (int i = 0; i < cnt[1]; ++i) {
        ans.push_back('0' + 1);
    }

    std::cout << ans << std::endl;
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