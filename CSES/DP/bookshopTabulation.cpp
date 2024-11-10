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

void Solve() {
    int n, x;cin>>n>>x;
    vi h(n), s(n);
    for(auto &p: h)cin>>p;
    for(auto &p: s)cin>>p;

    vll dp(x+1, 0);
    for(int i = 0; i<n; i++){
        for(int j = x; j>0; j--){
            if(h[i]>j){
                continue;
            }
            dp[j] = max(dp[j], s[i] + dp[j-h[i]]);
        }
    }
    cout<<dp[x]<<endl;
    return;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}