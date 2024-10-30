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
#define int long long
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;

vi a;
int n, k, z;
int calc(int ind, vvi &dp, int z_left, int move_left, int k_left){
    if(ind>=n || k_left==0) return 0;

    if(dp[ind][z_left]!=-1) return dp[ind][z_left];

    dp[ind][z_left] = 0;
    int A=0, B=0, C=0;
    if(k){
    if(ind>1 && z_left>0 && !move_left)
        B = calc(ind-1, dp, z_left-1, 1, k_left-1) + a[ind-1];
    C = calc(ind+1, dp, z_left, 0, k_left-1) + a[ind+1];
    }
    dp[ind][z_left] = max(dp[ind][z_left],B);
    dp[ind][z_left] = max(dp[ind][z_left],C);
    return dp[ind][z_left];
}
void Solve() {
    cin>>n>>k>>z;
    a.assign(n+1,0);
    for(int i = 1; i<=n; i++)cin>>a[i];
    z = min(z,1ll*5);
    vvi dp(n+1, vi(z+1,-1));
    int result = calc(0, dp, z, 0,k+1);
    cout<<result<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}