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
    vi a(n,0);int min_i, mn = 1e18;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(a[i]<mn){
            mn = a[i]; min_i = i;
        }
    }
    int ans = min_i;
    for(int i = min_i; i<n-1; i++){
        if(a[i+1]<a[i]) ans = -1;
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