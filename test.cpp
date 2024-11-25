#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        vector<int> a(n, 0);
        for(int i=0; i < n; ++i){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        
        int ret = 0;
        for(int i=0; i < n-2; ++i){
            if(a[i] + a[i+1] <= a.back()){ // if a + b <= c and a <= b <= c, set a = c
                ++ret;
            }
        }
        cout << ret << endl;
    }
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