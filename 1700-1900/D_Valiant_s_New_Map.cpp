#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n, m; 
bool check(int mid, vvi a){
    vvi pref(n+1, vi(m+1, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i][j]>=mid) a[i][j] = 1;
            else a[i][j] = 0;
            pref[i+1][j+1] = pref[i+1][j] + pref[i][j+1] - pref[i][j] + a[i][j];
        }
    }
    for(int i = mid; i<=n; i++){
        for(int j = mid; j<=m; j++){
            if(pref[i][j] - pref[i-mid][j] - pref[i][j-mid] + pref[i-mid][j-mid] == mid*mid) return true;
        }
    }
    return false;
}
void Solve() {
    cin>>n>>m;
    vvi a(n,vi(m,0));
    for(auto &x: a)
        for(auto &v: x) cin>>v;
    int lo = 1, hi = min(m,n);
    int ans = -1;
    while(lo<=hi){
        int mid = (hi-lo)/2 + lo;
        if(check(mid, a)){
            ans = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}