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
    vi h(n,0);
    map<int,int>mpp;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        mpp[x]++;
    }int mx = 0;
    for(auto &x: mpp){
        mx = max(mx, x.second);
    }
    cout<<n-mx<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}