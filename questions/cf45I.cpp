#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int neg = 0, zoro = 0, mxI = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            ++neg;
            if (mxI < 0 || a[i] > a[mxI]) {
                mxI = i;
            }
        } else if (a[i] == 0) {
            ++zoro;
        }
    }

    if (n == 1) {
        cout << a[0];
        return;
    }

    if (zoro == n || (neg == 1 && zoro == n - 1)) {
        cout << 0;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] != 0 && (neg % 2 == 0 || i != mxI)) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
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