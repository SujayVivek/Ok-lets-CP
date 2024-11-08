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
 int n, m;
int calc(int ind, int latest, vvi &dp){
    if(ind >= n) return 0;

    if(dp[ind][latest]!=-1)return dp[ind][latest];

    int left = calc()

}
void Solve() {
    cin>>n>>m;
    vi a(n), b(m);
    for(auto &x: a)cin>>x;
    for(auto &x: b)cin>>x;
    vvi dp(n+1, vi(m+1, -1));
    calc();
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}