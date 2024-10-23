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

int calc(int ind, vi &dp, vi &a, vi &b, int submit, vi &vis){
    if(ind == a.size()+1){
        return 0;
    }
    if(dp[ind]!=-1)return dp[ind];
    int result = 0;
    if(submit){
        for(int j = ind; j>=0; j--){
            if(!vis[j]){
                vis[j] = 1;
                result = max(result, calc(j, dp, a, b, 1, vis)+a[j]);
                vis[j] = 0;
                result = max(result, calc(j, dp, a, b, 0, vis));
            } 
        }
    }else{
        for(int j = b[ind]; j>=0 ;j--){
            if(!vis[j]){
                vis[j] = 1;
                result = max(result, calc(j, dp, a, b, 1, vis)+a[j]);
                vis[j] = 0;
                result = max(result , calc(j, dp, a, b, 0, vis));
            }
        }
    }
    return dp[ind] = max(dp[ind], result);
}
void Solve() {
    int n;cin>>n;
    vi a(n),b(n);
    for(auto &p: a)cin>>p;
    for(auto &p: b)cin>>p;
    vi dp(n+1, -1);
    vi vis(n+1, 0);
    int result =  calc(0, dp, a, b, 0, vis);
    result = max(result, a[0]);
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