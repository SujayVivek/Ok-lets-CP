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
    int n, x, y; cin>>n>>x>>y;
    int a, b;
    if(x+y<=n) {
        a = 1;
    }else{
        a = min(n,x+y-n+1);
    }
    b = min(n, x+y-1);
    cout<<a<<" "<<b<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}