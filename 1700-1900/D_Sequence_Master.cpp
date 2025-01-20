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
    int m;
    cin >> m;
    int n = 2 * m;
    vector<int> v(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        ans += abs(v[i]);
    }
    sort(v.begin(), v.end());

    if (n == 2)
    {
        cout << abs(v[0] - v[1]) << endl;
        return;
    }
    if (n == 4)
    {
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp += abs(v[i] - 2);
        }
        ans = min(ans, temp);
    }

    if (n % 4 == 0)
    {
        int temp = 0;
        for (int i = 0; i < n - 1; i++)
        {
            temp += abs(v[i] + 1);
        }
        temp += abs(v[n - 1] - n / 2);
        ans = min(ans, temp);
    }
    cout << ans << endl;
}


int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}