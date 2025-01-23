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
    int N; cin>>N;
    vi h(N+1,0);
    for(int i = 1; i<=N; i++){
        cin>>h[i];
    }
    
    vi dp(N+1, 1e9);
    dp[0] = 0; dp[1] = 0;
    for(int i = 1; i<=N; i++){
        if(i>1)dp[i] = min(dp[i], dp[i-1] + abs(h[i]-h[i-1]));
        if(i>2)dp[i] = min(dp[i], dp[i-2] + abs(h[i]-h[i-2]));
    }
    cout<<dp[N]<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}