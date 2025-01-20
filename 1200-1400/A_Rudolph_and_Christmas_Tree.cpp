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
    int n, d, h;
    cin >> n >> d >> h;
    double A = 0;
    vector<double> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i != 0 && a[i] < a[i - 1] + h)
        {
            A -= 0.5 * (a[i - 1] + h - a[i]) * (a[i - 1] + h - a[i]) * d / h;
        }
        A += 0.5 * d * h;
    }
    cout << fixed << setprecision(7) << A << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}