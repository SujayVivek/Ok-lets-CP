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
    int n, k, g;
    cin>>n>>k>>g;
    int x=(g - 1)/ 2;
    int ans;
    if (k*g<= n*x) {
        ans = 0;
    } else {
        ans = k*g -(n-1)*x;
        if (ans % g*2 >= g) {
            ans += g - ans % g;
        } else {
            ans -= ans % g;
        }
    }
    ans =  k*g-ans;
    cout << ans << "\n";
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}