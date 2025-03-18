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
    vi a(n,0);
    for(int i = 0; i<n; i++) cin>>a[i];
    vvi dp(n+1, vi(n+1, 0));
    for(int R = 2; R<n; R++){
        for(int L = R-2; L>=0; L--){
            for(int i = L+1; i<R; i++){
                dp[L][R] = max(dp[L][R], dp[L+1][i-1] + dp[i+1][R-1] + a[i]*a[L]*a[R]);
            }
            for(int i = L; i<R; i++) dp[L][R] = max(dp[L][R], dp[L][i] + dp[i+1][R]);
        }
    }
    cout<<dp[0][n-1]<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}