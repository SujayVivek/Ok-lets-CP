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
    int n, m, L;
    cin>>n>>m>>L;
    vector<pair<int,int>>hurdles;
    for(int i = 0; i<n; i++){
        int l, r; cin>>l>>r;
        hurdles.push_back({l,r});
    }
    vector<pair<int,int>>powers;
    int Sum = 0;
    for(int i = 0; i<m; i++){
        int x, y; cin>>x>>y;
        powers.push_back({x,y});
        Sum+=y;
    }
    
}   

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}