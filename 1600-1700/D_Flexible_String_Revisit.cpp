#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int power(int x, int y, int p = mod)
{
    int res = 1;
    x %= p; 
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p; 
        y >>= 1;            
        x = (x * x) % p;  
    }
    return res;
}
int modInverse(int n, int p = mod){
    return power(n, p-2, p);
}
void Solve() {
    int n; cin>>n;
    string a, b; cin>>a>>b;
    if(a==b){
        cout<<0<<endl;return;
    }
    int dif = 0;
    for(int i = 0; i<a.length(); i++){
        if(a[i]!=b[i])dif++;
    }
    vi dp(n+1, 0);
    dp[1] = (power(2,n)-1+mod)%mod;
    for(int i = 2; i<=dif; i++){
        dp[i] = (n*dp[i-1]%mod -(i-1)*dp[i-2]%mod-n+mod)%mod*modInverse(n-(i-1), mod)%mod;
    }
    cout<<dp[dif]<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}