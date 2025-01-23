#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ff first
#define ss second
    typedef vector<vector<long long>>
        vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int L = 40;
void Solve() {
    int k, n; cin>>k>>n;
    vvi dp(L, vi(k+1, 0));
    
    for(int i = 0; i<L; i++){
        for(int j = 1; j<=k; j++){
            for(int y = 2; y<= k/j; y++){
                dp[i+1][j*y]+= dp[i][j];
            }
        }
    }
    vi x_ans(k+1, 0);
    for(int i = 0; i<L && i<=n; i++){
        for(int j = 1; j<=k; j++){
            int C = dp[i][j];
            C*= f1[i+1]*inv[i+1]
        }
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