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
    int ans = 0;
    bool ok = true;
    for(int i = 0; i<n; i++){
        string s; cin>>s;
        m-=s.length();
        if(m<0 && ok){
            ok = false;
            ans = i;
        }
    }
    if(m>=0){
        ans = n;
    }
    cout<<ans<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}