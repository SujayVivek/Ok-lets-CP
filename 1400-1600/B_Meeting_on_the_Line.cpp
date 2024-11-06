#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define endl "\n"
#define pb push_back
#define MP make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;

void Solve() {
    int n;
    cin >> n;
    vector<double> x(n, 0);
    for (auto &p : x) cin >> p;
    vector<double> t(n, 0);
    double mx = -1;
    vector<double> v;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (t[i] > mx) {
            v.clear();
            v.pb(x[i]);
            mx = t[i];
        } else if (t[i] == mx) {
            v.pb(x[i]);
        }
    }
    double s = 0;
    for (auto it : v) {
        s += it;
    }
    s = s / v.size();
    double ans = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] < mx) {
            double c = mx - t[i];
            if (abs(x[i] - s) >= c) {
                ans += abs(x[i] - s) - c;
            }
        } else {
            ans += x[i];
        }
    }
    cout << fixed << setprecision(6) << ans / n << "\n";
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
