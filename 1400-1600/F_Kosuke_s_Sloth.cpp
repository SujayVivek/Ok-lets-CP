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
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n % MOD << endl;
        return;
    }
    ll a = 1, b = 1;
    ll cnt = 2;
    while (1) {
        ll c = (a%k + b%k)%k;
        cnt++;
        if (c == 0) {
            ll ans = (cnt % MOD) * (n % MOD) % MOD;
            cout << ans << endl;
            return;
        }
        a = b,b = c;
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
