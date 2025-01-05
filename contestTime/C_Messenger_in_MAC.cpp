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
    int n, l; cin>>n>>l;
    vvi v;
    for(int i = 0; i<n; i++){
        int a, b; cin>>a>>b;
        v.push_back({a,b});
    }
    vi dp(n+1, 1e9);
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            int T =  v[i][0] + abs(v[j][1]-v[i][1]);
            if(T+ dp[i]<=l) dp[j] = min(dp[j], dp[i] + T);
            dp[j] = min(dp[j],1e9);
        }
    }
    for(int i = 0; i<)
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}