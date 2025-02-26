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
    int n;
    cin >> n; string a;
    cin >> a;
    string s, b;
    if (a[0] != '9') {
        s = string(n, '9');
    } else {
        s = string(n + 1, '1');
    }
    reverse(a.begin(), a.end());
    int v = 0;
    for (int i = 0; i < n; i++) {
        int t = s[i] - a[i] - v;
        if (t < 0) {
            t += 10;
            v = 1;
        } else {
            v = 0;
        }
        b += '0' + t;
    }
    reverse(b.begin(), b.end());
    cout << b << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}