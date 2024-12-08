#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>

void Solve() {
    int n, m;
    cin >> n >> m;
    vi a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 1;
    if (m < n) {
        cout << 0 << endl;
        return;
    } else {
        for (int i = 0; i < n ; i++) {
            for (int j = i +1; j < n; j++) { 
                ans *= (abs(a[j] - a[i]) % m)%m;
                ans%=m;
                if (ans == 0) {
                    cout << 0 << endl;
                    return;
                }
            }
        }
        cout << ans % m << endl;
        return;
    }
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
