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
    int n, m, k; cin>>n>>m>>k;
    int X, Y; cin>>X>>Y;
    bool ok = true;
    for(int i = 0; i<k; i++){
        int x, y; cin>>x>>y;
        if((x+y)%2 == (X+Y)%2) ok = false;
    }
    if(ok)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}