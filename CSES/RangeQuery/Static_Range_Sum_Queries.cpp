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
    int q; cin>>q;
    int v[n];
    for(int i = 0; i<n; i++) cin>>v[i];
    for(int i = 1; i<n; i++) v[i]+= v[i-1];
    while(q--){
        int l, r; cin>>l>>r; l--, r--;
        if(l>0) cout<< v[r] - v[l-1];
        else cout<< v[r];
        cout<<endl;
    }
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}