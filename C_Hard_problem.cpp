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
    vi c(n,0);
    vector<string> S, Srev;
    for(auto &x: c) cin>>x;
    for(int i = 0; i<n; i++){
        string q; cin>>q;
        S.push_back(q);
        reverse(q.begin(), q.end());
        Srev.push_back(q);
    }
    int dp[n+1][2];
    dp[0][0] = 0, dp[0][1] = c[0];
    for(int i = 1; i<n; i++){
        dp[i][0] = 1e18, dp[i][1] = 1e18;
        if(S[i]>=S[i-1]) dp[i][0] = min(dp[i][0], dp[i-1][0]);
        if(S[i]>=Srev[i-1]) dp[i][0] = min(dp[i][0], dp[i-1][1]);
        if(Srev[i]>=S[i-1]) dp[i][1] = min(dp[i][1], dp[i-1][0] + c[i]);
        if(Srev[i]>=Srev[i-1]) dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]);
        if(dp[i][0]==1e18 && dp[i][1]==1e18){
            cout<<-1<<endl; return;
        }
    }
    cout<<min(dp[n-1][0], dp[n-1][1])<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}