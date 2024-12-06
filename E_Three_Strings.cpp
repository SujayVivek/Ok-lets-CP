#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
string a, b, c;

int calc(int i, int j, vvi &dp, int n, int m){
    if(i==n){
        int res = 0;
        while(j<m){
            if(c[i+j]!=b[j]){
                res++;
            }
            j++;
        }
        return res;
    }
    if(j==m){
        int res = 0;
        while(i<n){
            if(c[i+j]!=a[i]){
                res++;
            }
            i++;
        }
        return res;
    }
    if(i+j>=c.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int left = 0, right = 0;
    if(c[i+j]!=a[i]) left = calc(i+1, j, dp, n, m) + 1;
    else left = calc(i+1, j, dp, n, m);
    if(c[i+j]!=b[j]) right = calc(i, j+1, dp, n, m) + 1;
    else right = calc(i, j+1, dp, n, m  );

    return dp[i][j] = min(left, right);
}
void Solve() {
    cin>>a>>b>>c;
    int n = a.length(), m = b.length();
    vvi dp(n+1, vi(m+1, -1));
    int result = calc(0, 0, dp, n, m);
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