#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi fact(500001, 1), ifact(500001, 1);
int nCr(int n, int r) {
    if(r > n || r < 0) return 0;
    return ((fact[n]*ifact[r]) % mod*ifact[n-r]) %mod;
}
int Pow(int x, int y) {
    int res = 1;
    while(y > 0) {
        if(y & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

void calc() {
    for (int i = 2; i <= 500000; i++)
        fact[i] = (fact[i-1] * i) % mod;
    
    ifact[500000] = Pow(fact[500000], mod - 2);
    
    for (int i = 500000 - 1; i >= 0; i--)
        ifact[i] = (ifact[i+1] * (i+1)) % mod;
}
void Solve() {
    vi c(26);
    int S= 0; 
    for (int i = 0; i < 26; i++) {
        cin >> c[i]; 
        S += c[i];
    }
    int RemOdd =(S+1)/2;  
    int RemEve =S-RemOdd; 

    vi dp(RemOdd+1, 0);
    dp[0] = 1;
    for (int i = 0; i < 26; i++) {
        if(c[i] == 0) continue;
        for (int j =RemOdd; j>=c[i]; j--)
            dp[j]= (dp[j]+dp[j-c[i]]) % mod;
    }
    int A = dp[RemOdd]; 
    int Ans = (fact[RemOdd]*fact[RemEve]) % mod;
    int pTot = 0;
    for(int i = 0; i<RemOdd-1;i++) pTot+= dp[i];
    // cout<<pTot<<endl;
    for (int i = 0; i<26;i++) {
        if(c[i]>0)
            Ans =(Ans*ifact[c[i]]) % mod;
            // cout<<Ans<<" HI"<<endl;
    }
    cout<<(A*Ans)%mod<<endl;
}

int32_t main() {
    int tt_;
    cin >> tt_;
    calc();
    while (tt_--)
        Solve();
    return 0;
}