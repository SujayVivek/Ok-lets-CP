#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

string P, P_rev;
int dp[10001][2][2];

int calc(int idx, int hi, int lo) {
    if (idx == P.size()) return hi && lo; // Both conditions must be satisfied
    if (dp[idx][hi][lo] != -1) return dp[idx][hi][lo];
    
    int ans = 0;
    char start = hi ? 'A' : P[idx];       // Start from P[idx] if not already larger
    char end = lo ? 'Z' : P_rev[idx];    // End at P_rev[idx] if not already larger

    for (char c = start; c <= end; c++) {
        int new_hi = hi || (c > P[idx]);       // `hi` becomes true if c > P[idx]
        int new_lo = lo || (c < P_rev[idx]);  // `lo` becomes true if c > P_rev[idx]
        ans = (ans + calc(idx + 1, new_hi, new_lo)) % mod;
    }
    
    return dp[idx][hi][lo] = ans;
}

void Solve() {
    memset(dp, -1, sizeof(dp));
    cin >> P;
    P_rev = P;
    reverse(P_rev.begin(), P_rev.end());
    cout << calc(0, 0, 0) << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
