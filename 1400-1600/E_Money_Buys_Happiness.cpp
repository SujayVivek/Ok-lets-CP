#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve()
{   
    int n, x; cin>>n>>x;
    int m = 0;
    vi c(n+1), h(n+1);
    for (int i = 1; i <= n; i++)
        {cin>>c[i]>>h[i]; m += h[i];}
    vvi dp(n+1, vi(m+1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m; j++)
            if (dp[i][j] >= 0)
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + x);
                if (dp[i][j] >= c[i + 1])
                    dp[i + 1][j + h[i + 1]] = max(dp[i + 1][j + h[i + 1]], dp[i][j] - c[i + 1] + x);
            }
    int res = 0;
    for (int i = 0; i <= m; i++)
        if (dp[n][i] >= 0)
            res = max(res, i);
    cout<<res<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}