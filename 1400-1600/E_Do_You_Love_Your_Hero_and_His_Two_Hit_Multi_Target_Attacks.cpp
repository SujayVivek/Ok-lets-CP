#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void Solve() {
    int k;
    cin >> k;
    
    vector<array<int, 2>> ans;
    int x = 0;
    int y = 0;
    while (k) {
        x++;
        int s = 1;
        while (s * (s + 1) / 2 <= k) {
            s++;
        }
        k -= s * (s - 1) / 2;
        for (int i = 1; i <= s; i++) {
            y++;
            ans.push_back({x, y});
        }
    }
    cout << ans.size() << "\n";
    for (auto it : ans) {
        cout << it[0] << " " << it[1]<< "\n";
    }
}

int32_t main() {
    int tt_;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
