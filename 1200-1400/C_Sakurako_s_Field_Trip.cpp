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
    int N;
    cin >> N;
    vector<int> a(N);
    for (auto &x : a)cin >> x;
    int d = 0;
    for (int i = 0; i < N - 1; i++)
        d += a[i] == a[i + 1];
    int p = 0;
    for (int i = 0; i<(N - 1)/2+1; i++) {
        int q = (a[i] == a[i + 1]) + (a[N - 2 - i] == a[N - 1 - i]);
        q -= (a[i] == a[N - 2 - i]) + (a[i + 1] == a[N - 1 - i]);
        p += max(q, 0);
    }
    cout << d - p << '\n';
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}