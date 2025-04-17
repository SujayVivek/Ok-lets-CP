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
    int XOR = 0; for(int i = 1; i<=n*2; i++)XOR^=i;
    vi ans;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int x; cin>>x;
            if(i==0 || j==n-1) {XOR^=x; ans.push_back(x);}
        }
    }cout<<XOR<<" ";
    for(auto &x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}