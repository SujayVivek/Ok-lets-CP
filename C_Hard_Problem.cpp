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
    int m, a, b, c; cin>>m>>a>>b>>c;
    int cnt = 0;
    int A = min(m, a), B = min(m , b);
    int left = 2*m -A -B;
    left = max(0ll , left -c);
    cout<<2*m - left<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}