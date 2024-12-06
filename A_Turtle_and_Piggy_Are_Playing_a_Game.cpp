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
    int l, r; cin>>l>>r;
    int j = 1;
    int mx = 0;
    for(int i =1; i<35; i++){
        j = j<<1;
        if(j>=l && j<=r){
            mx = max(mx, i);
        }
    }
    cout<<mx<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}