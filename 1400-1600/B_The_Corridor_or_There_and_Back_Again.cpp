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
    vvi v(n,vi(2,0));
    for(int i = 0; i<n; i++){
        int d, s; cin>>d>>s;
        v[i] = {d,s};
    }
    sort(v.begin(), v.end());
    int mx_dist = 1e9;
    for(int i = 0; i<n; i++){
        mx_dist = min(mx_dist, v[i][0] + (v[i][1]-1)/2);
    }
    cout<<mx_dist<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}