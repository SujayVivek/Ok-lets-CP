#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int biggest_double = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            biggest_double = i;
        }
    }
    if (biggest_double == -1)
    {
        cout << -1 << "\n";
        return;
    }

    int x = a[biggest_double];
    a.erase(a.begin() + biggest_double);
    a.erase(a.begin() + biggest_double - 1);

    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] -a[i-1]< 2 * x)
        {
            cout << x << " " << x << " " << a[i - 1] << " " << a[i] << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}