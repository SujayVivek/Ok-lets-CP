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
    string s;
    cin >> s;
    int n = s.size();
    string rs = s;
    reverse(rs.begin(), rs.end());
    string t = rs + "#" + s; int m = t.size();
    vi pi(m, 0);
    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j > 0 && t[i] != t[j])
            j = pi[j - 1];
        if (t[i] == t[j])
            j++;
        pi[i] = j;
    }
    int l = pi[m - 1];
    string add = s.substr(0, n - l); reverse(add.begin(), add.end());
    string ans = s + add;
    cout << ans <<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
