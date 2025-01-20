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
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    int st = (3 * n + 1) / 2;
    for (int i = 1; i <= n; i += 2)
    {
        cout << i << " " << st << "\n";
        st--;
    }
    st = 2 * n;
    for (int i = 2; i <= n; i += 2)
    {
        cout << i << " " << st << "\n";
        st--;
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