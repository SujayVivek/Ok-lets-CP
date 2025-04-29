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
    int n; cin>>n;
    vi a(n,0);
     for (auto &x: a)cin>>x;
     for(int i = 1; i<n ;i++) a[i]+= a[i-1]; int mx = 0;
     for(int i = 0; i<n; i++){
        mx = max(mx, (a[i]+i)/(i+1));
     }int q; cin>>q;
     for(int i = 0; i<q; i++){
        int x; cin>>x;
        if(x<mx)cout<<-1<<endl;
        else cout<<(a[n-1]+x-1)/x<<endl;
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