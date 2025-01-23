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
    int n,s; cin>>n>>s;
    vi a(n+1,0);
    vi x(n+1,0), y(n+1,0);
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        if(i==0 || i==n-1){x[i] = a[i], y[i] = a[i];}
        else{
            if(a[i]<=s){
                x[i] = 0, y[i] = a[i];
            }else{
                x[i] = s; y[i] = a[i]-s;
            }
        }
    }
    vvi dp(n+2, vi(2,0));
    for(int i = 2; i<=n; i++){
        dp[i][0] = min(dp[i-1][0] + y[i-1]*x[i], dp[i-1][1] + x[i-1]*x[i]);
        dp[i][1] = min(dp[i-1][0] + y[i-1]*y[i], dp[i-1][1] + x[i-1]*y[i]);
    }
    cout<<dp[n][0]<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}