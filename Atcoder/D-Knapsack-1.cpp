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
    int N, W; cin>>N>>W;
    vi w(N,0), v(N,0);
    for(int i = 0; i<N; i++){
        cin>>w[i]>>v[i];
    }
    int mx = 0;
    vvi dp(N+1, vi(W+1, -1));
    dp[0][0] = 0;
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<=W; j++){
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
            if(j>=w[i-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]]+v[i-1]);
            if(i==N)mx = max(mx, dp[i][j]);
        }
    }
    cout<<mx<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}