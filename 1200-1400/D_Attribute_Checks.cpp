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

int calc(int ind,int I_attr, vvi &dp, vi &r, int n, int m, int P){
    if(ind == n){
        return 0;
    }
    if(dp[ind][I_attr]!=-1){
        return dp[ind][I_attr];
    }
    dp[ind][I_attr] = 0;
    int i = 0, j = 0;
    if(r[ind] == 0){
        P++;
        i+=  calc(ind+1, I_attr + 1, dp, r, n , m,P);
        j+=   calc(ind+1, I_attr, dp, r, n, m ,P);
    }else if(r[ind] >0){
        if(I_attr>=r[ind]){
            return 1;
        }
    }else if(r[ind]< 0){
        if(P-I_attr >=abs(r[ind])){
            return 1;
        }
    }
    dp[ind][I_attr] = max(i,j);
    return dp[ind][I_attr];
}
void Solve() {
    int n, m;cin>>n>>m;
    vi r(n,0);
    for(auto &x:r)cin>>x;
    vvi dp(n+1, vi(m,-1));
    int result = calc(0, 0,dp,r,n,m,0);
    cout<<result<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}