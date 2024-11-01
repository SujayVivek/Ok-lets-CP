#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define endl "\n"
#define pb push_back
#define MP make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
#define int long long
const int N=1010,mod=1e9+7;
ll dp[N][N];
void Solve()
{
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=1000;i++)
            dp[1][i]=1,dp[i][0]=1;
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=(dp[i][j-1]+dp[i-1][n-j])%mod;
            }
        }
    cout<<dp[k][n]<<endl;
    return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}