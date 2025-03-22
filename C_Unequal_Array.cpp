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
    vi a(n,0);
    for(auto &x: a) cin>>x;
    int mx = 0, mn = 1e18;
    for(int i = 0; i<n-1; i++){
        if(a[i]==a[i+1]) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    if(mn>=mx) cout<<0<<endl;
    else cout<< max(1ll, mx-mn-1)<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}