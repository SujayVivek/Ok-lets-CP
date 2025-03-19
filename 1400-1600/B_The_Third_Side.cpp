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
    for(int i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end(), greater<int>());
    if(n==1){cout<<a[0]<<endl;return;}
    for(int i = 0; i<n-1; i++){
        a[i+1] = a[i] + a[i+1] - 1;
    }
    cout<<a[n-1]<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}