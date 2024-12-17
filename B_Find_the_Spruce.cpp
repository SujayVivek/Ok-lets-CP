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
    int n, m; cin>>n>>m;
    vector<string> grid(n);
    for(int i = 0; i<n; i++){
        cin>>grid[i];
    }
    vvi dp(n, vi(m, 0));
    int ans = 0;
    for(int i = n-1; i>=0; i--){
        for(int j = 0; j<m; j++){
            if(grid[i][j]=='*'){
                if(i<n-1 & j>0 && j<m-1){
                    dp[i][j] = min(min(dp[i+1][j], dp[i+1][j-1]), dp[i+1][j+1]);
                }
                dp[i][j]++;
                ans+= dp[i][j];
            }
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}