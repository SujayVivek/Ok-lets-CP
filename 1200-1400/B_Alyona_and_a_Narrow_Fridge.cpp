#include <bits/stdc++.h>

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define loopm(ii, i, n, p) for (ll ii = i; ii < n; ii+=p)
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define MP make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;

bool check(ll mid, vll &v, int h) {
    vll a(v.begin(), v.begin() + mid); // Copy the first `mid` elements
    sort(all(a), greater<int>()); // Sort in descending order
    ll sum = 0;
    for (int i = 0; i < a.size(); i += 2) {
        sum += a[i];
    }
    return sum <= h;
}

void Solve() {
    // Your code for each test case goes here
    ll n, h;
    cin >> n >> h;
    vll v(n, 0); 
    loop(i, 0, n) {
        cin >> v[i];
    }
    ll lo = 0, hi = n;
    ll ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid, v, h)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    fastio();
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
