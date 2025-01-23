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
    int n, l, r;
    cin >> n >> l >> r;
    l--, r--;
    vi a(n, 0);
    for (auto &x : a)
        cin >> x;
    vector<int> b, c;
    for (int i = l; i < n; i++)
    {
        b.push_back(a[i]);
    }
    for (int i = 0; i <= r; i++)
    {
        c.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int sum1 = accumulate(b.begin(), b.begin() + (int)(r - l + 1), 0LL);
    int sum2 = accumulate(c.begin(), c.begin() + (int)(r - l + 1), 0LL);

    cout << min(sum1, sum2) << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}