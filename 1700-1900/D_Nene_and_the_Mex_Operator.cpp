#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi pref;
int calc(int L, int R, vvi &dp){
    if(L==R)return 0;

    if(dp[L][R]!=-1)return dp[L][R];
    int ans = 0;
    for(int mid = L; mid<R; mid++){
        int S1 = pref[mid];
        if(L>0) S1-= pref[L-1];
        int S2 = pref[R];
        if(mid>=0) S2-=pref[mid];

        ans = max(ans, S1+S2);
        ans = max(ans, S2 + (mid-L+1)*(mid-L+1));
        ans = max(ans, S1 + (R-mid + 1)*(R-mid + 1));
        ans = max(ans, (R-L+1)*(R-L+1));
        ans = max(ans, calc(L, mid, dp));
        ans = max(ans, calc(mid+1, R, dp));
    }
    return dp[L][R] = ans;
}
void Solve() {
    int n; cin>>n;
    vi a(n,0);
    pref.assign(n+1, 0);
    for(auto &x: a)cin>>x;
    pref[0] = a[0];
    for(int i = 1; i<n; i++) pref[i] = pref[i-1]+ a[i];
    vvi dp(n+1, vi(n+1, -1));
    int result = calc(0,n-1,dp);
    cout<<result<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}