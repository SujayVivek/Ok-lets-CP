#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n, m, k; 
vvi h, v;
int dp[505][505][23];

int calc(int i, int j, int K){
    if(i<0 || i>n-1 || j<0 || j>m-1) return 1e18;
    if(K == 0) return 0;
    if(dp[i][j][K]!=1e18) return dp[i][j][K];
    int ans = 1e18;
    if(j<m) ans = min(ans, calc(i, j+1, K-2) + 2*h[i][j]);
    if(j>0) ans = min(ans, calc(i, j-1, K-2) + 2*h[i][j-1]);
    if(i<n) ans = min(ans, calc(i+1, j, K-2) + 2*v[i][j]);
    if(i>0) ans = min(ans, calc(i-1, j, K-2) + 2*v[i-1][j]);
    return dp[i][j][K] = ans;
}
void Solve() {
    cin>>n>>m>>k;
    h.assign(n, vi (m));
    v.assign(n, vi(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m-1; j++){
            cin>>h[i][j];
        }
    } 
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<m; j++){
            cin>>v[i][j];
        }
    }
    for(int i = 0; i<505; i++){
        for(int j = 0; j<505; j++){
            for(int k = 0; k<23; k++) dp[i][j][k] = 1e18;
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(k%2==1) cout<<-1<<" ";
            else
            cout<< calc(i, j, k)<<" ";
        }cout<<endl;
    }
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}