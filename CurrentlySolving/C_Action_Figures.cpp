#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int calc(int idx, int num_zero, string s, vvi &dp){
    if(idx==s.length()){
        return 0;
    }
    if(dp[idx][num_zero]!=-1) return dp[idx][num_zero];
    if(s[idx]=='0') num_zero++;
    int left = 1e9, right = 1e9;
    if(num_zero){
        left = calc(idx + 1, num_zero-1, s, dp) + idx;
    }
    right = calc(idx + 1, num_zero, s, dp);
    return dp[idx][num_zero] = min(left, right);
}
void Solve() {
    int n; cin>>n;
    string s; cin>>s;
    vvi dp(n+1, vi(n+1, -1));
    int result = calc(0, 0, s, dp);
    cout<<result<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}