#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int power(int a, int b, int m){
    int res = 1;
    while(b>0){
        if(b&1) res = res*a%m;
        a = a*a%m;
        b>>=1;
    }
    return res;
}
int modInverse(int a, int m){
    return power(a, m-1, m);
}
void Solve() {
    int n; cin>>n;
    int o = 0, e = 0;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        if(x%2)o++;
        else e++;
    }
    int T = 1;
    for(int i = 1; i<=e; i++){
        T = (T*2)%mod;
    }
    int Ans = 0;
    Ans = max(0ll, (T-(1+e+(e*(e-1))/2)+mod)%mod);
    int P = 1;//16C0
    for(int i = 2; i<=o; i++){
        P = (P*(o-i+1)*(o-i+2)*modInverse(i*(i-1), mod))%mod;
        if(i==2) Ans+= P*(T-1)%mod;
        else Ans+= P*T%mod;
    }
    cout<<Ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}