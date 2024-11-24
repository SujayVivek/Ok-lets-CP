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
    int n, b, c; cin>>n>>b>>c;
        if (b == 0) {
			if (c >= n) {
				cout << n << endl;
			} else if (c >= n - 2) {
				cout << n - 1 << endl;
			} else {
				cout << -1 << endl;
			}
		} else {
		    if (c >= n) cout << n << endl;
			else cout << n - max(0ll, 1 + (n - c - 1) / b) << endl;
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