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
    int n, m; cin>>n>>m;
    int l = max(0ll, n-m), r = n+m;
    int ans = 0;
    for(int i = 31; i>=0; i--){
        if((r&(1ll<<i))||(l&(1ll<<i))||(l>>(i+1)!=r>>(i+1))){
            ans|= 1ll<<i;
        }
    }
    cout<<ans<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}