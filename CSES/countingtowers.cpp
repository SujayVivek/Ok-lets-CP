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

int calc(int sum, int lat_ind, vvi &dp, vi &v){
    if(sum<0 || lat_ind>=v.size()) return 0;
    if(sum==0) return 1;
    if(dp[sum][lat_ind]!=-1) return dp[sum][lat_ind];

    dp[sum][lat_ind] = 0;
    for(int i = lat_ind; i<v.size(); i++){
            dp[sum][lat_ind] = (dp[sum][lat_ind]+calc(sum-v[i], v[i], dp, v))%MOD;
    }
    return dp[sum][lat_ind]%MOD;
}
void Solve() {
    int n;cin>>n;
    vi v;
    for(int i = 1; i<= n; i++){
        if(n%i==0) v.pb(i);
    }
    reverse(all(v));
    vvi dp(2*n+1, vi(v.size()+1, -1));
    int result = calc(2*n, 0, dp, v);
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