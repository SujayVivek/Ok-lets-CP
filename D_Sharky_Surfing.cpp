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
    int n, m, L;
    cin >> n >> m >> L;
    
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    
    priority_queue<int> pq;
    
    vector<int> x(m), v(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> v[i];
    }
    
    int cur = 1;
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < m && x[j] < l[i]) {
            pq.push(v[j]);
            j++;
        }
        while (cur < r[i] - l[i] + 2) {
            if (pq.empty()) {
                cout << -1 << endl;
                return;
            }
            cur += pq.top();
            pq.pop();
            ans++;
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}