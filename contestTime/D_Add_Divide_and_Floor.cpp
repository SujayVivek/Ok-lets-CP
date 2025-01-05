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
    int MX = 0, MN = 1e9;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        MX = max(MX, a[i]);
        MN = min(MN, a[i]);
    }
    if(n==1){
        cout<<0<<endl;return;
    }
    if(MX == MN){
        cout<<0<<endl;return;
    }
    int ans = log2(MX-MN) + 1;
    cout<< ans <<endl;
        if(ans<=n){
            for(int i = 0; i<ans; i++){
            cout<<MN<<" ";
        }
        cout<<endl;
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