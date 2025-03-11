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
    int n, m, k; cin>>n>>m>>k;
    vector<tuple<int, int, int>> v(m);
    vector<pair<int,int>> distances(m); map<int,int> mpp;
    for(int i = 0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        v[i] = {a , b, c}; distances[i] = {c, i};
        mpp[i] = c;
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