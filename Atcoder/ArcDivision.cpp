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
    int n, r; cin>>n>>r;
    while(n--){
        int D, A; cin>>D>>A;
        if(D==1 && 1600<=r && r<=2799){
            r+= A;
        }else if(D==2 && 1200<=r && r<=2399){
            r+= A;
        }
        // cout<<r<<endl;
    }
    cout<<r<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}