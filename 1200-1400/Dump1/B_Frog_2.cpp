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
    int n, k; cin>>n>>k;
    vi h(n,0);
    for(auto &x: h)cin>>x;
    vi dp(n+1, 1e9);
    dp[0] = 0;
    for(int i = 0; i<n; i++){
        for(int j = 1; j<=min(n-i-1,k); j++){
            dp[i+j] = min(dp[i+j], dp[i] + abs(h[j+i]-h[i]));
        }
    }
    cout<<dp[n-1]<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}