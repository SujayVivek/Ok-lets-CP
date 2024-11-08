#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef vector<int> vi;
#define int long long
#define endl "\n"

string s, t;
void Solve() {
    cin>>s>>t;
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i = 0; i<=n; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j<=m; j++){
        dp[0][j] = j;
    }
    for(int i = 1; i<=n ; i++){
        for(int j = 1; j<=m; j++){
            char x = s[i-1], y = t[j-1];
            if(x==y){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = dp[i-1][j-1] + 1;
            }

            dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
        }
    }
    cout<<dp[n][m]<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}