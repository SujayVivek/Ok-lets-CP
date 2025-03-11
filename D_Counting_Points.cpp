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
    int n, m; cin>>n>>m;
    vi x(n,0), r(n,0);
    for(auto &b: x) cin>>b; 
    for(auto &b: r) cin>>b;
    vvi vp;
    for(int i = 0; i<n; i++){
        for(int j = -r[i]; j<=r[i]; j++){
            int pts = sqrt(r[i]*r[i]-j*j);
            vp.push_back({x[i]+ j, pts});
        }
    }
    sort(vp.begin(), vp.end()); int j = 0, ans = 0;
    for(int i = 0; i<vp.size(); i = j){
        while(j<vp.size() && vp[i][0] == vp[j][0]) j++;
        int A  = 0;
        for(int k = i; k<j; k++) A = max(A, vp[k][1]);
        ans+= 2*A+1;
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}