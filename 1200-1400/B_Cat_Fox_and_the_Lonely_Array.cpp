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
    int OR = 0;
    vi a(n,0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int ans = 1;
    for(int j = 0; j<30; j++){
        vi v;
        for(int i = 0; i<n; i++){
            if(a[i]>>j &1) v.push_back(i);
        }
        int mx = 0, last = -1;
        for(auto it: v){
            mx = max(mx, it-last);
            last = it;
        }
        mx = max(mx, n-last);
        if(last!=-1) ans = max(ans, mx);
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