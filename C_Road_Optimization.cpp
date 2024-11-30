#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n, l, k;

int calc(int ind, int k, int last, vector<vector<vector<int>>> &dp, vi &d, vi &s) {
    if (ind == n) {
        return s[last] * (l - d[ind - 1]);
    }
    if (dp[ind][k][last] != -1) return dp[ind][k][last];
    int keep = calc(ind + 1, k, ind, dp, d, s) + s[last] * (d[ind] - d[ind - 1]);
    int skip = (k > 0) ? calc(ind + 1, k - 1, last, dp, d, s) + s[last] * (d[ind] - d[ind - 1]) : 1e18;

    return dp[ind][k][last] = min(keep, skip);
}

void Solve() {
    cin >> n >> l >> k;
    vi d(n, 0), s(n, 0);
    for (auto &x : d) cin >> x;
    for (auto &x : s) cin >> x;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(n, -1)));


    int result = calc(1, k, 0, dp, d, s);
    cout << result << endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
