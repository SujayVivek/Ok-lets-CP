#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef vector<int> vi;
#define int long long
#define endl "\n"
 
int calc(int i, int j, vi &a, vector<vi>&dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = max(a[i] - calc(i+1, j, a, dp), a[j] - calc(i, j-1, a, dp));
}
void Solve() {
    int n; cin>>n; 
    vi a(n,0);
    int s = 0;
    for(auto &x: a){cin>>x; s+=x;}
    vector<vi> dp(n, vi(n, -1));
    int result = calc(0, n-1, a, dp);
    cout<<(result+s)/2<<endl;return;
}
 
int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
