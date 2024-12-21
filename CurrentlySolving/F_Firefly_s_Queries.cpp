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
    int n, q; cin>>n>>q;
    vi a(n,0), pref(2*n + 1, 0);
    int sum = 0;
    for(auto &x: a) cin>>x;
    for(int i = 0; i<n; i++) {a.push_back(a[i]); sum+= a[i];}
    for(int i = 0; i<2*n; i++){
        pref[i+1] = pref[i] + a[i];
    }
    while(q--){
        int l, r; cin>>l>>r; int ans = 0; l--;
        int lNum = l/n, rNum = r/n, lMod = l%n, rMod = r%n;
        ans+= (r/n - l/n)*sum;
        ans+= pref[rNum + rMod] - pref[rNum];
        ans-= pref[lNum + lMod] - pref[lNum];
        cout<<ans<<endl;
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