#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
const int m = 998244353;
void Solve() {
    int n; cin>>n;
     vi a(n,0);
     for(int i = 0; i<n; i++) cin>>a[i];
     int no_1s = 0, no_2s = 0, Ans = 0;
     vi pref(n+1,0);
     for(int i = 0; i<n; i++){
        if(a[i]==1){no_1s = (no_1s+1)%m;}
        if(a[i]==2){no_2s = (no_2s*2)%m; no_2s= (no_2s+no_1s)%m;}
        if(a[i]==3){Ans= (Ans+no_2s)%m;}
     }
     cout<<Ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}