#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int MX = LLONG_MIN, MN = LLONG_MAX;
int n;
int calc(int mx, int mn, vi &a, vvi &dp){
    if((mx-mn) == (n-1)) return 0;
    if(dp[mx][mn]!=-1) return dp[mx][mn];

    int ans = 1e18;
    if(mx<n-1) ans = min(ans, calc(mx + 1, mn, a, dp) + a[mx+1]-a[mn]);
    if(mn>0) ans = min(ans, calc(mx, mn-1, a, dp) + a[mx] - a[mn-1]);
    return dp[mx][mn] = ans;
}

void Solve() {
    cin>>n;
    vi a(n,0);
    for(int i = 0; i<n; i++) {cin>>a[i]; MX = max(MX, a[i]), MN = min(MN, a[i]);}
    if(n==1){cout<<0<<endl;return;}
    sort(a.begin(), a.end());
    int Ans = 1e18;
    vvi dp(n+1, vi(n+1, -1));
    for(int i = 0; i<n; i++){
        Ans = min(Ans, calc(i,i, a, dp));
    }
    cout<<Ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}