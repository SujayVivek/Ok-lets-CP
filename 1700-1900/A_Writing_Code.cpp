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
    int n, m, b, MOD; cin>>n>>m>>b>>MOD;
    vi Bugs(n);
    for(auto &x: Bugs) cin>>x;
    int dp[2][m+1][b+1];
    for(int i = 0; i<=1; i++){
        for(int j = 0; j<=m; j++){
            for(int k = 0; k<=b; k++){
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    for(int i = 1; i<=n; i++){
        int p = i&1;
        for(int j = 0; j<=m; j++){
            for(int k = 0; k<=b; k++){
                dp[p][j][k] = dp[1-p][j][k];
                if(j>0 && k>=Bugs[i-1]){
                    dp[p][j][k] = (dp[p][j][k] + dp[p][j-1][k-Bugs[i-1]])%MOD;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i<= b; i++){
        ans = (ans + dp[n&1][m][i])%MOD;
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}