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
    vvi dp(n, vi((n*(n+1)/2) + 1,0));
    dp[0][0] = 1;
    if((n*(n+1)/2)%2==1){cout<<0<<endl; return;}
    for(int i = 1; i<n; i++){
        for(int j = 0; j<= n*(n+1)/4; j++){
            dp[i][j] = dp[i-1][j];
            if(j-i>=0)
            dp[i][j]=  (dp[i][j]+dp[i-1][j-i])%mod;
        }
    }
    cout<< dp[n-1][n*(n+1)/4]<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}