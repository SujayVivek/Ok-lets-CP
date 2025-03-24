#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int dp[2005][2005];
void Solve() {
    int n,k;
	cin >> k >> n;
	dp[0][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			for(int x=j;x<=k;x+=j)
			{
				dp[i][x]=(dp[i][x]+dp[i-1][j])%mod;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=k;i++)
		ans=(ans+dp[n][i])%mod;
	cout << ans;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}