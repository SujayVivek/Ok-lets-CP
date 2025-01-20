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
    int n; cin>>n;
    vi a(n+1,0);
    for(int i = 1; i<=n; i++) cin>>a[i];
    vvi dp(n+2, vi(n+2));
    for(int i = n; i>=1; i--){
        for(int j = i; j<=n; j++){
            if(i == j) {dp[i][j] = 1; continue;}
            dp[i][j] = dp[i+1][j] + 1;
            if(a[i] == a[i+1]) dp[i][j] = min(dp[i][j], 1 + dp[i+2][j]);
            for(int k = i+2; k<=j; k++){
                if(a[i] == a[k]){
                    dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k+1][j]);
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}