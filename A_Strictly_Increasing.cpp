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
    for(auto &x: a) cin>>x;
    for(int i = 0; i<n-1; i++){
        if(a[i+1]<=a[i]){
            cout<<"No"<<endl;return;
        }
    }
    cout<<"Yes"<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}