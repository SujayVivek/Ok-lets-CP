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
    int s  = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        s+= a[i];
    }
    if(s%3){
        cout<<0<<endl;return;
    }
    s/=3;
    int subSum = 0;
    vi cnt(n,0);
    for(int i = n-1; i>=0; i--){
        subSum+= a[i];
        if(subSum==s) cnt[i]++;
    }
    for(int i = n-2; i>=0; i--){
        cnt[i] += cnt[i+1];
    }
    int ans = 0;
    subSum = 0;
    for(int i = 0; i<n-2; i++){
        subSum+= a[i];
        if(subSum == s) ans+= cnt[i+2];
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}