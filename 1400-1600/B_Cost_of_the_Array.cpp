#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n, k;
    cin >> n >> k;
    k /= 2;
    vector<int> a(n);
    for (auto &it: a) cin >> it;
    if (2 * k == n) {
        for (int i = 1; i < n; i += 2) {
            if (a[i] != (i + 1) / 2) {
                cout << (i + 1) / 2 << endl;
                return;
            }
        }
        cout << k + 1 << endl;
    } else {
        for (int i = 1; i <= n - 2 * k + 1; i++) {
            if (a[i] != 1) {
                cout << 1<<endl;
                return;
            }
        }
        cout << 2<<endl;
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}