#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n; cin>>n;
    vvi v(n, vi(2));
    for(int i = 0; i<n; i++){
        int t, V; cin>>t>>V;
        v[i] = {t, V};
    }
    int t_end = v[n-1][0];
    int ans = v[0][1];
    for(int i = 1; i<n; i++){
        ans-= (v[i][0]-v[i-1][0]);
        if(ans<0) ans = 0;
        ans+= v[i][1];
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}