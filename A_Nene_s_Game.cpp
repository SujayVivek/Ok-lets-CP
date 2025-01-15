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
    int k, q; cin>>k>>q;
    int mn = 1e9;
    for(int i = 0; i<k; i++){
        int x; cin>>x;
        mn = min(mn, x);
    }
    for(int i = 0; i<q; i++){
        int x; cin>>x;
        cout<<min(x, mn-1)<<" ";
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}