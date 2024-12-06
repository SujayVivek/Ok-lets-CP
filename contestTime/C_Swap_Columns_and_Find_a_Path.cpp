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
    int NEG = -2*1e5-1;
    vvi v(2, vi(n,0));
    for(int i = 0; i<n; i++){
        cin>>v[0][i];
    }
    for(int i = 0; i<n; i++){
        cin>>v[1][i];
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(v[0][i]>v[1][i]) {
            ans += v[0][i];
            v[0][i] = NEG;
        }else{
            ans += v[1][i];
            v[1][i] = NEG;
        }
    }int mx = NEG;
    for(int i = 0; i<n; i++){
        mx = max(mx, v[1][i]);
        mx = max(mx, v[0][i]);
    }
    cout<<ans+mx<<endl;return;

}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}