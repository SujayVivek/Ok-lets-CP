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
    int n, k; cin>>n>>k;
    vi a(n,0); int tot_sum = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    vi pref(n+1);
    for(int i = 0; i<n; i++){
        pref[i+1] = pref[i] + a[i];
    }
    int ans = -1e9;
    for(int i = 0; i<=k; i++){
        ans = max(ans, pref[n-(k-i)]-pref[2*i]);
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