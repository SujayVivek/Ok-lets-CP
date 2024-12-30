#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n, m, b, MOD; 
int calc(int idx, int ms, int bs, vector<vector<vector<int>>>&dp, vi &Bugs){
    if(idx == n) {
    return (ms == m && bs <= b) ? 1 : 0;
    }

    if(dp[idx][ms][bs]!=-1) return dp[idx][ms][bs];
    dp[idx][ms][bs] = 0;
    for(int i = 0; i<=m-ms; i++){
        if(Bugs[idx]*i<=(b-bs)){
            dp[idx][ms][bs]= (dp[idx][ms][bs] +  calc(idx + 1, ms + i, bs + Bugs[idx]*i, dp , Bugs)%MOD)%MOD;
        }
    }
    return dp[idx][ms][bs];
}
void Solve() {
    cin>>n>>m>>b>>MOD;
    vi Bugs(n);
    for(auto &x: Bugs) cin>>x;
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vi(b+1, -1)));
    int result = calc(0, 0, 0, dp, Bugs);
    cout<<result%MOD<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}