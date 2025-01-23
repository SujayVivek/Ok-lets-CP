#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n;
int calc(int idx, int Liars, char prev, vvi &dp, vi &a){
    if(idx>n){
        return 1;
    }
    if(dp[idx][Liars]!=-1) return dp[idx][Liars];
    int ans = 0;
    if(prev!='L'){
        ans+= calc(idx + 1, Liars+1, 'L', dp, a);
    }
    if(a[idx] == Liars){
        ans+= calc(idx + 1, Liars, 'H', dp , a);
    }
    return dp[idx][Liars] = ans;
}
void Solve() {
    cin>>n;
    vi a(n+1,0);
    for(int i = 1; i<=n; i++) cin>>a[i];
    vvi dp(n+1, vi(n+1, -1));
    cout<<calc(1,0,'P',dp, a)<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}