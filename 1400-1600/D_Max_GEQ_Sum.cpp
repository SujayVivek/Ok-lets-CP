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
    vi a(n,0); int mx = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mx = max(mx, a[i]);
    }
    int S = a[0]; int ans = -1e18; bool ok = false;
    for(int i = 1; i<n; i++){
        ans = max(ans, S);
        S+= a[i];
        if(S<0){ ans = max(ans, S), S = 0;}
        if(ans> mx){ ok = true; break;}
    }
    ans = max(ans, S);
    if(ans> mx) ok = true;
    if(ok){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
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