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
    int k, l1, r1, l2, r2;
    cin>>k>>l1>>r1>>l2>>r2;
    int r = 1, ans = 0;
    for(int i = 0; i<=32; i++){
        ans += max(0ll, min(r1, (r2)/r) - max(l1, (l2 + r-1)/r) + 1) ;
        r*=k;
        if(r>r2)break;
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