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
    int n, k, x; cin>>n>>k>>x;
    if((k*(k+1)/2 > x) || ((n*(n+1)/2) - ((n-k)*(n-k+1)/2))<x) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}